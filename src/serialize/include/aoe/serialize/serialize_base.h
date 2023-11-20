#pragma once

#include <array>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <cxxabi.h>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "aoe/serialize/byte_orderer.h"
#include "aoe/serialize/enable_if.h"
#include "aoe/serialize/enumerable.h"
#include "aoe/serialize/float_details.h"
#include "aoe/serialize/map_pair.h"
#include "aoe/serialize/vectorstream.h"

#if __cplusplus >= 201703L
#include <optional>
#include <variant>
#endif

namespace aoe::serialize
{
    void check_serialized_version(const std::string& expected_version, std::istream& in);

    // ----------------------------------------------------------------------------------------

    /*!A ramdump information !*/
    template <typename T>
    struct ramdump_t
    {
        /*!
            WHAT THIS OBJECT REPRESENTS
                This is a type decoration used to indicate that serialization should be
                done by simply dumping the memory of some object to disk as fast as
                possible without any sort of conversions.  This means that the data written
                will be "non-portable" in the sense that the format output by a RAM dump
                may depend on things like the endianness of your CPU or settings of certain
                compiler switches.

                You use this object like this:
                   serialize("yourfile.dat") << ramdump(yourobject);
                   deserialize("yourfile.dat") >> ramdump(yourobject);
                or
                   serialize(ramdump(yourobject), out);
                   deserialize(ramdump(yourobject), in);

                Also, not all objects have a ramdump mode.  If you try to use ramdump on an
                object that does not define a serialization dump for ramdump you will get a
                compiler error.
        !*/
        ramdump_t(T& item_)
            : item(item_)
        {
        }
        T& item;
    };

    // This function just makes a ramdump that wraps an object.
    template <typename T>
    ramdump_t<typename std::remove_reference<T>::type> ramdump(T&& item)
    {
        return ramdump_t<typename std::remove_reference<T>::type>(item);
    }

    template <typename T>
    void serialize(const ramdump_t<const T>& item_, std::ostream& out)
    {
        // Move the const from inside the ramdump_t template to outside so we can bind
        // against a serialize() call that takes just a const ramdump_t<T>.  Doing this
        // saves you from needing to write multiple overloads of serialize() to handle
        // these different const placement cases.
        const auto temp = ramdump(const_cast<T&>(item_.item));
        serialize(temp, out);
    }

    // ----------------------------------------------------------------------------------------

    namespace ser_helper
    {

        template <typename T>
        typename enable_if_c<std::numeric_limits<T>::is_signed, bool>::type pack_int(T item, std::ostream& out)
        /*!
            requires
                - T is a signed integral type
            ensures
                - if (no problems occur serializing item) then
                    - writes item to out
                    - returns false
                - else
                    - returns true
        !*/
        {
            // COMPILE_TIME_ASSERT(sizeof(T) <= 8);
            unsigned char buf[9];
            unsigned char size = sizeof(T);
            unsigned char neg;
            if (item < 0)
            {
                neg = 0x80;
                item *= -1;
            }
            else
            {
                neg = 0;
            }

            for (unsigned char i = 1; i <= sizeof(T); ++i)
            {
                buf[i] = static_cast<unsigned char>(item & 0xFF);
                item >>= 8;
                if (item == 0)
                {
                    size = i;
                    break;
                }
            }

            std::streambuf* sbuf = out.rdbuf();
            buf[0]               = size | neg;
            if (sbuf->sputn(reinterpret_cast<char*>(buf), size + 1) != size + 1)
            {
                out.setstate(std::ios::eofbit | std::ios::badbit);
                return true;
            }

            return false;
        }

        // ------------------------------------------------------------------------------------

        template <typename T>
        typename enable_if_c<std::numeric_limits<T>::is_signed, bool>::type unpack_int(T& item, std::istream& in)
        /*!
            requires
                - T is a signed integral type
            ensures
                - if (there are no problems deserializing item) then
                    - returns false
                    - #item == the value stored in in
                - else
                    - returns true

        !*/
        {
            // COMPILE_TIME_ASSERT(sizeof(T) <= 8);

            unsigned char buf[8];
            unsigned char size;
            bool          is_negative;

            std::streambuf* sbuf = in.rdbuf();

            item   = 0;
            int ch = sbuf->sbumpc();
            if (ch != EOF)
            {
                size = static_cast<unsigned char>(ch);
            }
            else
            {
                in.setstate(std::ios::badbit);
                return true;
            }

            if (size & 0x80)
                is_negative = true;
            else
                is_negative = false;
            size &= 0x0F;

            // check if the serialized object is too big
            if (size > (unsigned long)tmin<sizeof(T), 8>::value || size == 0)
            {
                return true;
            }

            if (sbuf->sgetn(reinterpret_cast<char*>(&buf), size) != size)
            {
                in.setstate(std::ios::badbit);
                return true;
            }

            for (unsigned char i = size - 1; true; --i)
            {
                item <<= 8;
                item |= buf[i];
                if (i == 0)
                    break;
            }

            if (is_negative)
                item *= -1;

            return false;
        }

        // ------------------------------------------------------------------------------------

        template <typename T>
        typename disable_if_c<std::numeric_limits<T>::is_signed, bool>::type pack_int(T item, std::ostream& out)
        /*!
            requires
                - T is an unsigned integral type
            ensures
                - if (no problems occur serializing item) then
                    - writes item to out
                    - returns false
                - else
                    - returns true
        !*/
        {
            // COMPILE_TIME_ASSERT(sizeof(T) <= 8);
            unsigned char buf[9];
            unsigned char size = sizeof(T);

            for (unsigned char i = 1; i <= sizeof(T); ++i)
            {
                buf[i] = static_cast<unsigned char>(item & 0xFF);
                item >>= 8;
                if (item == 0)
                {
                    size = i;
                    break;
                }
            }

            std::streambuf* sbuf = out.rdbuf();
            buf[0]               = size;
            if (sbuf->sputn(reinterpret_cast<char*>(buf), size + 1) != size + 1)
            {
                out.setstate(std::ios::eofbit | std::ios::badbit);
                return true;
            }

            return false;
        }

        // ------------------------------------------------------------------------------------

        template <typename T>
        typename disable_if_c<std::numeric_limits<T>::is_signed, bool>::type unpack_int(T& item, std::istream& in)
        /*!
            requires
                - T is an unsigned integral type
            ensures
                - if (there are no problems deserializing item) then
                    - returns false
                    - #item == the value stored in in
                - else
                    - returns true

        !*/
        {
            // COMPILE_TIME_ASSERT(sizeof(T) <= 8);

            unsigned char buf[8];
            unsigned char size;

            item = 0;

            std::streambuf* sbuf = in.rdbuf();
            int             ch   = sbuf->sbumpc();
            if (ch != EOF)
            {
                size = static_cast<unsigned char>(ch);
            }
            else
            {
                in.setstate(std::ios::badbit);
                return true;
            }

            // mask out the 3 reserved bits
            size &= 0x8F;

            // check if an error occurred
            if (size > (unsigned long)tmin<sizeof(T), 8>::value || size == 0)
                return true;

            if (sbuf->sgetn(reinterpret_cast<char*>(&buf), size) != size)
            {
                in.setstate(std::ios::badbit);
                return true;
            }

            for (unsigned char i = size - 1; true; --i)
            {
                item <<= 8;
                item |= buf[i];
                if (i == 0)
                    break;
            }

            return false;
        }

    }  // namespace ser_helper

    // ----------------------------------------------------------------------------------------

#define USE_NODE_DEFAULT_INT_SERIALIZATION_FOR(T)                                                                                          \
    inline void serialize(const T& item, std::ostream& out)                                                                                \
    {                                                                                                                                      \
        if (ser_helper::pack_int(item, out))                                                                                               \
            throw std::runtime_error("error serializing object of type " + std::string(#T));                                               \
    }                                                                                                                                      \
    inline void deserialize(T& item, std::istream& in)                                                                                     \
    {                                                                                                                                      \
        if (ser_helper::unpack_int(item, in))                                                                                              \
            throw std::runtime_error("error deserializing object of type " + std::string(#T));                                             \
    }

    template <typename T>
    inline bool pack_byte(const T& ch, std::ostream& out)
    {
        std::streambuf* sbuf = out.rdbuf();
        return (sbuf->sputc((char)ch) == EOF);
    }

    template <typename T>
    inline bool unpack_byte(T& ch, std::istream& in)
    {
        std::streambuf* sbuf = in.rdbuf();
        int             temp = sbuf->sbumpc();
        if (temp != EOF)
        {
            ch = static_cast<T>(temp);
            return false;
        }
        else
        {
            return true;
        }
    }

#define USE_NODE_DEFAULT_BYTE_SERIALIZATION_FOR(T)                                                                                         \
    inline void serialize(const T& item, std::ostream& out)                                                                                \
    {                                                                                                                                      \
        if (pack_byte(item, out))                                                                                                          \
            throw std::runtime_error("error serializing object of type " + std::string(#T));                                               \
    }                                                                                                                                      \
    inline void deserialize(T& item, std::istream& in)                                                                                     \
    {                                                                                                                                      \
        if (unpack_byte(item, in))                                                                                                         \
            throw std::runtime_error("error deserializing object of type " + std::string(#T));                                             \
    }

    // ----------------------------------------------------------------------------------------

    USE_NODE_DEFAULT_INT_SERIALIZATION_FOR(short)
    USE_NODE_DEFAULT_INT_SERIALIZATION_FOR(int)
    USE_NODE_DEFAULT_INT_SERIALIZATION_FOR(long)
    USE_NODE_DEFAULT_INT_SERIALIZATION_FOR(unsigned short)
    USE_NODE_DEFAULT_INT_SERIALIZATION_FOR(unsigned int)
    USE_NODE_DEFAULT_INT_SERIALIZATION_FOR(unsigned long)
#if defined (__APPLE__)
    // LINUX 不需要？
    USE_NODE_DEFAULT_INT_SERIALIZATION_FOR(uint64_t)
    USE_NODE_DEFAULT_INT_SERIALIZATION_FOR(int64_t)
#endif
    USE_NODE_DEFAULT_BYTE_SERIALIZATION_FOR(char)
    USE_NODE_DEFAULT_BYTE_SERIALIZATION_FOR(signed char)
    USE_NODE_DEFAULT_BYTE_SERIALIZATION_FOR(unsigned char)

// Don't define serialization for wchar_t when using visual studio and
// _NATIVE_WCHAR_T_DEFINED isn't defined since if it isn't they improperly set
// wchar_t to be a typedef rather than its own type as required by the C++
// standard.
#if !defined(_MSC_VER) || _NATIVE_WCHAR_T_DEFINED
    USE_NODE_DEFAULT_INT_SERIALIZATION_FOR(wchar_t)
#endif

    // ----------------------------------------------------------------------------------------

    inline void serialize(const float_details& item, std::ostream& out)
    {
        serialize(item.mantissa, out);
        serialize(item.exponent, out);
    }

    inline void deserialize(float_details& item, std::istream& in)
    {
        deserialize(item.mantissa, in);
        deserialize(item.exponent, in);
    }

    // ----------------------------------------------------------------------------------------

    template <typename T>
    inline void serialize_floating_point(const T& item, std::ostream& out)
    {
        try
        {
            float_details temp = item;
            serialize(temp, out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing a floating point number.");
        }
    }

    template <typename T>
    inline bool old_deserialize_floating_point(T& item, std::istream& in)
    {
        std::ios::fmtflags oldflags = in.flags();
        in.flags(static_cast<std::ios_base::fmtflags>(0));
        std::streamsize ss = in.precision(35);
        if (in.peek() == 'i')
        {
            item = std::numeric_limits<T>::infinity();
            in.get();
            in.get();
            in.get();
        }
        else if (in.peek() == 'n')
        {
            item = -std::numeric_limits<T>::infinity();
            in.get();
            in.get();
            in.get();
            in.get();
        }
        else if (in.peek() == 'N')
        {
            item = std::numeric_limits<T>::quiet_NaN();
            in.get();
            in.get();
            in.get();
        }
        else
        {
            in >> item;
        }
        in.flags(oldflags);
        in.precision(ss);
        return (in.get() != ' ');
    }

    template <typename T>
    inline void deserialize_floating_point(T& item, std::istream& in)
    {
        // check if the serialized data uses the older ASCII based format.  We can check
        // this easily because the new format starts with the integer control byte which
        // always has 0 bits in the positions corresponding to the bitmask 0x70.  Moreover,
        // since the previous format used ASCII numbers we know that no valid bytes can
        // have bit values of one in the positions indicated 0x70.  So this test looks at
        // the first byte and checks if the serialized data uses the old format or the new
        // format.
        if ((in.rdbuf()->sgetc() & 0x70) == 0)
        {
            try
            {
                // Use the fast and compact binary serialization format.
                float_details temp;
                deserialize(temp, in);
                item = temp;
            }
            catch (std::runtime_error& e)
            {
                throw std::runtime_error(std::string(e.what()) + "\n   while deserializing a floating point number.");
            }
        }
        else
        {
            if (old_deserialize_floating_point(item, in))
                throw std::runtime_error("error deserializing a floating point number.");
        }
    }

    inline void serialize(const float& item, std::ostream& out)
    {
        serialize_floating_point(item, out);
    }

    inline void deserialize(float& item, std::istream& in)
    {
        deserialize_floating_point(item, in);
    }

    inline void serialize(const double& item, std::ostream& out)
    {
        serialize_floating_point(item, out);
    }

    inline void deserialize(double& item, std::istream& in)
    {
        deserialize_floating_point(item, in);
    }

    inline void serialize(const long double& item, std::ostream& out)
    {
        serialize_floating_point(item, out);
    }

    inline void deserialize(long double& item, std::istream& in)
    {
        deserialize_floating_point(item, in);
    }

    // ----------------------------------------------------------------------------------------

    template <typename T>
    inline void serialize(const std::complex<T>& item, std::ostream& out)
    {
        try
        {
            serialize(item.real(), out);
            serialize(item.imag(), out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing an object of type std::complex");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename T>
    inline void deserialize(std::complex<T>& item, std::istream& in)
    {
        try
        {
            T real, imag;
            deserialize(real, in);
            deserialize(imag, in);
            item = std::complex<T>(real, imag);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing an object of type std::complex");
        }
    }

    // ----------------------------------------------------------------------------------------
    // prototypes

    template <typename domain, typename range, typename compare, typename alloc>
    void serialize(const std::map<domain, range, compare, alloc>& item, std::ostream& out);

    template <typename domain, typename range, typename compare, typename alloc>
    void deserialize(std::map<domain, range, compare, alloc>& item, std::istream& in);

    template <typename domain, typename range, typename hash, typename keyEqual, typename alloc>
    void serialize(const std::unordered_map<domain, range, hash, keyEqual, alloc>& item, std::ostream& out);

    template <typename domain, typename range, typename hash, typename keyEqual, typename alloc>
    void deserialize(std::unordered_map<domain, range, hash, keyEqual, alloc>& item, std::istream& in);

    template <typename domain, typename range, typename compare, typename alloc>
    void serialize(const std::multimap<domain, range, compare, alloc>& item, std::ostream& out);

    template <typename domain, typename range, typename compare, typename alloc>
    void deserialize(std::multimap<domain, range, compare, alloc>& item, std::istream& in);

    template <typename domain, typename range, typename hash, typename keyEqual, typename alloc>
    void serialize(const std::unordered_multimap<domain, range, hash, keyEqual, alloc>& item, std::ostream& out);

    template <typename domain, typename range, typename hash, typename keyEqual, typename alloc>
    void deserialize(std::unordered_multimap<domain, range, hash, keyEqual, alloc>& item, std::istream& in);

    template <typename domain, typename compare, typename alloc>
    void serialize(const std::set<domain, compare, alloc>& item, std::ostream& out);

    template <typename domain, typename compare, typename alloc>
    void deserialize(std::set<domain, compare, alloc>& item, std::istream& in);

    template <typename domain, typename hash, typename keyEqual, typename alloc>
    void serialize(const std::unordered_set<domain, hash, keyEqual, alloc>& item, std::ostream& out);

    template <typename domain, typename hash, typename keyEqual, typename alloc>
    void deserialize(std::unordered_set<domain, hash, keyEqual, alloc>& item, std::istream& in);

    template <typename domain, typename compare, typename alloc>
    void serialize(const std::multiset<domain, compare, alloc>& item, std::ostream& out);

    template <typename domain, typename compare, typename alloc>
    void deserialize(std::multiset<domain, compare, alloc>& item, std::istream& in);

    template <typename domain, typename hash, typename keyEqual, typename alloc>
    void serialize(const std::unordered_multiset<domain, hash, keyEqual, alloc>& item, std::ostream& out);

    template <typename domain, typename hash, typename keyEqual, typename alloc>
    void deserialize(std::unordered_multiset<domain, hash, keyEqual, alloc>& item, std::istream& in);

    template <typename T, typename alloc>
    void serialize(const std::vector<T, alloc>& item, std::ostream& out);

    template <typename T, typename alloc>
    void deserialize(std::vector<T, alloc>& item, std::istream& in);

    template <typename T, typename alloc>
    void serialize(const std::list<T, alloc>& item, std::ostream& out);

    template <typename T, typename alloc>
    void deserialize(std::list<T, alloc>& item, std::istream& in);

    template <typename T, typename alloc>
    void serialize(const std::forward_list<T, alloc>& item, std::ostream& out);

    template <typename T, typename alloc>
    void deserialize(std::forward_list<T, alloc>& item, std::istream& in);

    template <typename T, typename alloc>
    void serialize(const std::deque<T, alloc>& item, std::ostream& out);

    template <typename T, typename alloc>
    void deserialize(std::deque<T, alloc>& item, std::istream& in);

    template <typename... Types>
    void serialize(const std::tuple<Types...>& item, std::ostream& out);

    template <typename... Types>
    void deserialize(std::tuple<Types...>& item, std::istream& in);

    template <typename T, typename deleter>
    void serialize(const std::unique_ptr<T, deleter>& item, std::ostream& out);

    template <typename T, typename deleter>
    void deserialize(std::unique_ptr<T, deleter>& item, std::istream& in);

    template <typename T>
    void serialize(const std::shared_ptr<T>& item, std::ostream& out);

    template <typename T>
    void deserialize(std::shared_ptr<T>& item, std::istream& in);

    inline void serialize(const std::string& item, std::ostream& out);

    inline void deserialize(std::string& item, std::istream& in);

    inline void serialize(const std::wstring& item, std::ostream& out);

    inline void deserialize(std::wstring& item, std::istream& in);

    // inline void serialize(const ustring& item, std::ostream& out);

    // inline void deserialize(ustring& item, std::istream& in);

    template <typename T>
    inline void serialize(const enumerable<T>& item, std::ostream& out);

    template <typename domain, typename range>
    inline void serialize(const map_pair<domain, range>& item, std::ostream& out);

    template <typename T, size_t length>
    inline void serialize(const T (&array)[length], std::ostream& out);

    template <typename T, size_t length>
    inline void deserialize(T (&array)[length], std::istream& in);

    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------
    // ----------------------------------------------------------------------------------------

    inline void serialize(bool item, std::ostream& out)
    {
        if (item)
            out << '1';
        else
            out << '0';

        if (!out)
            throw std::runtime_error("error serializing object of type bool");
    }

    inline void deserialize(bool& item, std::istream& in)
    {
        int ch = in.get();
        if (ch != EOF)
        {
            if (ch == '1')
                item = true;
            else if (ch == '0')
                item = false;
            else
                throw std::runtime_error("error deserializing object of type bool");
        }
        else
        {
            throw std::runtime_error("error deserializing object of type bool");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename first_type, typename second_type>
    void serialize(const std::pair<first_type, second_type>& item, std::ostream& out)
    {
        try
        {
            serialize(item.first, out);
            serialize(item.second, out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::pair");
        }
    }

    template <typename first_type, typename second_type>
    void deserialize(std::pair<first_type, second_type>& item, std::istream& in)
    {
        try
        {
            deserialize(item.first, in);
            deserialize(item.second, in);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::pair");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <std::size_t I = 0, typename FuncT, typename... Tp>
    inline typename std::enable_if<I == sizeof...(Tp), void>::type for_each_in_tuple(std::tuple<Tp...>&, FuncT)
    {
    }

    template <std::size_t I = 0, typename FuncT, typename... Tp>
        inline typename std::enable_if < I<sizeof...(Tp), void>::type for_each_in_tuple(std::tuple<Tp...>& t, FuncT f)
    {
        f(std::get<I>(t));
        for_each_in_tuple<I + 1, FuncT, Tp...>(t, f);
    }

    template <std::size_t I = 0, typename FuncT, typename... Tp>
    inline typename std::enable_if<I == sizeof...(Tp), void>::type for_each_in_tuple(const std::tuple<Tp...>&, FuncT)
    {
    }

    template <std::size_t I = 0, typename FuncT, typename... Tp>
        inline typename std::enable_if < I<sizeof...(Tp), void>::type for_each_in_tuple(const std::tuple<Tp...>& t, FuncT f)
    {
        f(std::get<I>(t));
        for_each_in_tuple<I + 1, FuncT, Tp...>(t, f);
    }

    struct serialize_tuple_helper
    {
        explicit serialize_tuple_helper(std::ostream& out_)
            : out(out_)
        {
        }

        template <typename T>
        void operator()(const T& item)
        {
            serialize(item, out);
        }

        std::ostream& out;
    };

    struct deserialize_tuple_helper
    {
        deserialize_tuple_helper(std::istream& in_)
            : in(in_)
        {
        }

        template <typename T>
        void operator()(T& item)
        {
            deserialize(item, in);
        }

        std::istream& in;
    };

    template <typename... Types>
    void serialize(const std::tuple<Types...>& item, std::ostream& out)
    {
        try
        {
            for_each_in_tuple(item, serialize_tuple_helper(out));
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::tuple");
        }
    }

    template <typename... Types>
    void deserialize(std::tuple<Types...>& item, std::istream& in)
    {
        try
        {
            for_each_in_tuple(item, deserialize_tuple_helper(in));
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::tuple");
        }
    }

    // ----------------------------------------------------------------------------------------

#if __cplusplus >= 201703L

    namespace detail
    {
        template <typename Variant, std::size_t I = 0>
        void deserialize_variant_helper(Variant& item, std::istream& in, std::size_t index)
        {
            if constexpr (I < std::variant_size_v<Variant>)
            {
                if (I == index)
                {
                    auto& x = item.template emplace<std::variant_alternative_t<I, Variant>>();
                    deserialize(x, in);
                }
                else
                {
                    deserialize_variant_helper<Variant, I + 1>(item, in, index);
                }
            }
            else
            {
                throw std::runtime_error("deserialize_variant_helper() index is out of range of variant size");
            }
        }
    }  // namespace detail

    template <typename... Types>
    void serialize(const std::variant<Types...>& item, std::ostream& out)
    {
        serialize(item.index(), out);
        std::visit(
            [&out](const auto& x)
            {
                serialize(x, out);
            },
            item);
    }

    template <typename... Types>
    void deserialize(std::variant<Types...>& item, std::istream& in)
    {
        std::size_t index = 0;
        deserialize(index, in);
        detail::deserialize_variant_helper(item, in, index);
    }

    template <typename T>
    void serialize(const std::optional<T>& item, std::ostream& out)
    {
        serialize(item.has_value(), out);
        if (item)
            serialize(item.value(), out);
    }

    template <typename T>
    void deserialize(std::optional<T>& item, std::istream& in)
    {
        bool has_value = false;
        deserialize(has_value, in);
        if (has_value)
        {
            deserialize(item.has_value() ? item.value() : item.emplace(), in);
        }
        else
        {
            item.reset();
        }
    }

#endif

    // ----------------------------------------------------------------------------------------

    template <typename domain, typename range, typename compare, typename alloc>
    void serialize(const std::map<domain, range, compare, alloc>& item, std::ostream& out)
    {
        try
        {
            const unsigned long size = static_cast<unsigned long>(item.size());

            serialize(size, out);
            typename std::map<domain, range, compare, alloc>::const_iterator i;
            for (i = item.begin(); i != item.end(); ++i)
            {
                serialize(i->first, out);
                serialize(i->second, out);
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::map");
        }
    }

    template <typename domain, typename range, typename compare, typename alloc>
    void deserialize(std::map<domain, range, compare, alloc>& item, std::istream& in)
    {
        try
        {
            item.clear();

            unsigned long size;
            deserialize(size, in);
            domain d;
            range  r;
            for (unsigned long i = 0; i < size; ++i)
            {
                deserialize(d, in);
                deserialize(r, in);
                item[d] = r;
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::map");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename domain, typename range, typename hash, typename keyEqual, typename alloc>
    void serialize(const std::unordered_map<domain, range, hash, keyEqual, alloc>& item, std::ostream& out)
    {
        try
        {
            serialize(item.size(), out);
            for (const auto& x : item)
            {
                serialize(x.first, out);
                serialize(x.second, out);
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::unordered_map");
        }
    }

    template <typename domain, typename range, typename hash, typename keyEqual, typename alloc>
    void deserialize(std::unordered_map<domain, range, hash, keyEqual, alloc>& item, std::istream& in)
    {
        try
        {
            item.clear();
            std::size_t size;
            deserialize(size, in);
            domain d;
            range  r;
            for (unsigned long i = 0; i < size; ++i)
            {
                deserialize(d, in);
                deserialize(r, in);
                item[d] = r;
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::unordered_map");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename domain, typename range, typename compare, typename alloc>
    void serialize(const std::multimap<domain, range, compare, alloc>& item, std::ostream& out)
    {
        try
        {
            serialize(item.size(), out);
            for (const auto& x : item)
            {
                serialize(x.first, out);
                serialize(x.second, out);
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::multimap");
        }
    }

    template <typename domain, typename range, typename compare, typename alloc>
    void deserialize(std::multimap<domain, range, compare, alloc>& item, std::istream& in)
    {
        try
        {
            item.clear();
            std::size_t size;
            deserialize(size, in);
            domain d;
            range  r;
            for (unsigned long i = 0; i < size; ++i)
            {
                deserialize(d, in);
                deserialize(r, in);
                item.insert({ d, r });
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::multimap");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename domain, typename range, typename hash, typename keyEqual, typename alloc>
    void serialize(const std::unordered_multimap<domain, range, hash, keyEqual, alloc>& item, std::ostream& out)
    {
        try
        {
            serialize(item.size(), out);
            for (const auto& x : item)
            {
                serialize(x.first, out);
                serialize(x.second, out);
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::unordered_multimap");
        }
    }

    template <typename domain, typename range, typename hash, typename keyEqual, typename alloc>
    void deserialize(std::unordered_multimap<domain, range, hash, keyEqual, alloc>& item, std::istream& in)
    {
        try
        {
            item.clear();
            std::size_t size;
            deserialize(size, in);
            domain d;
            range  r;
            for (unsigned long i = 0; i < size; ++i)
            {
                deserialize(d, in);
                deserialize(r, in);
                item.insert({ d, r });
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::unordered_multimap");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename domain, typename compare, typename alloc>
    void serialize(const std::set<domain, compare, alloc>& item, std::ostream& out)
    {
        try
        {
            const unsigned long size = static_cast<unsigned long>(item.size());

            serialize(size, out);
            typename std::set<domain, compare, alloc>::const_iterator i;
            for (i = item.begin(); i != item.end(); ++i)
            {
                serialize(*i, out);
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::set");
        }
    }

    template <typename domain, typename compare, typename alloc>
    void deserialize(std::set<domain, compare, alloc>& item, std::istream& in)
    {
        try
        {
            item.clear();

            unsigned long size;
            deserialize(size, in);
            domain d;
            for (unsigned long i = 0; i < size; ++i)
            {
                deserialize(d, in);
                item.insert(d);
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::set");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename domain, typename hash, typename keyEqual, typename alloc>
    void serialize(const std::unordered_set<domain, hash, keyEqual, alloc>& item, std::ostream& out)
    {
        try
        {
            serialize(item.size(), out);
            for (const auto& x : item)
                serialize(x, out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::unordered_set");
        }
    }

    template <typename domain, typename hash, typename keyEqual, typename alloc>
    void deserialize(std::unordered_set<domain, hash, keyEqual, alloc>& item, std::istream& in)
    {
        try
        {
            item.clear();
            std::size_t size;
            deserialize(size, in);
            domain d;
            for (unsigned long i = 0; i < size; ++i)
            {
                deserialize(d, in);
                item.insert(d);
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::unordered_set");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename domain, typename compare, typename alloc>
    void serialize(const std::multiset<domain, compare, alloc>& item, std::ostream& out)
    {
        try
        {
            serialize(item.size(), out);
            for (const auto& x : item)
                serialize(x, out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::multiset");
        }
    }

    template <typename domain, typename compare, typename alloc>
    void deserialize(std::multiset<domain, compare, alloc>& item, std::istream& in)
    {
        try
        {
            item.clear();
            std::size_t size;
            deserialize(size, in);
            domain d;
            for (unsigned long i = 0; i < size; ++i)
            {
                deserialize(d, in);
                item.insert(d);
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::multiset");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename domain, typename hash, typename keyEqual, typename alloc>
    void serialize(const std::unordered_multiset<domain, hash, keyEqual, alloc>& item, std::ostream& out)
    {
        try
        {
            serialize(item.size(), out);
            for (const auto& x : item)
                serialize(x, out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::unordered_multiset");
        }
    }

    template <typename domain, typename hash, typename keyEqual, typename alloc>
    void deserialize(std::unordered_multiset<domain, hash, keyEqual, alloc>& item, std::istream& in)
    {
        try
        {
            item.clear();
            std::size_t size;
            deserialize(size, in);
            domain d;
            for (unsigned long i = 0; i < size; ++i)
            {
                deserialize(d, in);
                item.insert(d);
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::unordered_multiset");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename alloc>
    void serialize(const std::vector<bool, alloc>& item, std::ostream& out)
    {
        std::vector<unsigned char> temp(item.size());
        for (unsigned long i = 0; i < item.size(); ++i)
        {
            if (item[i])
                temp[i] = '1';
            else
                temp[i] = '0';
        }
        serialize(temp, out);
    }

    template <typename alloc>
    void deserialize(std::vector<bool, alloc>& item, std::istream& in)
    {
        std::vector<unsigned char> temp;
        deserialize(temp, in);
        item.resize(temp.size());
        for (unsigned long i = 0; i < temp.size(); ++i)
        {
            if (temp[i] == '1')
                item[i] = true;
            else
                item[i] = false;
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename T, typename alloc>
    void serialize(const std::vector<T, alloc>& item, std::ostream& out)
    {
        try
        {
            const auto size = static_cast<unsigned long>(item.size());

            serialize(size, out);
            for (unsigned long i = 0; i < item.size(); ++i)
                serialize(item[i], out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::vector");
        }
    }

    template <typename T, typename alloc>
    void deserialize(std::vector<T, alloc>& item, std::istream& in)
    {
        try
        {
            unsigned long size;
            deserialize(size, in);
            item.resize(size);
            for (unsigned long i = 0; i < size; ++i)
                deserialize(item[i], in);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::vector");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename alloc>
    void serialize(const std::vector<char, alloc>& item, std::ostream& out)
    {
        try
        {
            const auto size = static_cast<unsigned long>(item.size());
            serialize(size, out);
            if (item.size() != 0)
                out.write(&item[0], item.size());
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::vector");
        }
    }

    template <typename alloc>
    void deserialize(std::vector<char, alloc>& item, std::istream& in)
    {
        try
        {
            unsigned long size;
            deserialize(size, in);
            item.resize(size);
            if (item.size() != 0)
                in.read(&item[0], item.size());
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::vector");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename alloc>
    void serialize(const std::vector<unsigned char, alloc>& item, std::ostream& out)
    {
        try
        {
            const auto size = static_cast<unsigned long>(item.size());
            serialize(size, out);
            if (item.size() != 0)
                out.write((char*)&item[0], item.size());
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::vector");
        }
    }

    template <typename alloc>
    void deserialize(std::vector<unsigned char, alloc>& item, std::istream& in)
    {
        try
        {
            unsigned long size;
            deserialize(size, in);
            item.resize(size);
            if (item.size() != 0)
                in.read((char*)&item[0], item.size());
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::vector");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename T, typename alloc>
    void serialize(const std::list<T, alloc>& item, std::ostream& out)
    {
        try
        {
            const unsigned long size = static_cast<unsigned long>(item.size());
            serialize(size, out);
            for (const auto& x : item)
                serialize(x, out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::list");
        }
    }

    template <typename T, typename alloc>
    void deserialize(std::list<T, alloc>& item, std::istream& in)
    {
        try
        {
            unsigned long size;
            deserialize(size, in);
            item.resize(size);
            for (auto& x : item)
                deserialize(x, in);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::list");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename T, typename alloc>
    void serialize(const std::forward_list<T, alloc>& item, std::ostream& out)
    {
        try
        {
            const unsigned long size = std::distance(item.begin(), item.end());
            serialize(size, out);
            for (const auto& x : item)
                serialize(x, out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::forward_list");
        }
    }

    template <typename T, typename alloc>
    void deserialize(std::forward_list<T, alloc>& item, std::istream& in)
    {
        try
        {
            unsigned long size;
            deserialize(size, in);
            item.resize(size);
            for (auto& x : item)
                deserialize(x, in);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::forward_list");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename T, typename alloc>
    void serialize(const std::deque<T, alloc>& item, std::ostream& out)
    {
        try
        {
            const unsigned long size = static_cast<unsigned long>(item.size());

            serialize(size, out);
            for (unsigned long i = 0; i < item.size(); ++i)
                serialize(item[i], out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::deque");
        }
    }

    template <typename T, typename alloc>
    void deserialize(std::deque<T, alloc>& item, std::istream& in)
    {
        try
        {
            unsigned long size;
            deserialize(size, in);
            item.resize(size);
            for (unsigned long i = 0; i < size; ++i)
                deserialize(item[i], in);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::deque");
        }
    }

    // ----------------------------------------------------------------------------------------

    inline void serialize(const std::string& item, std::ostream& out)
    {
        const unsigned long size = static_cast<unsigned long>(item.size());
        try
        {
            serialize(size, out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::string");
        }

        out.write(item.c_str(), size);
        if (!out)
            throw std::runtime_error("error serializing object of type std::string");
    }

    inline void deserialize(std::string& item, std::istream& in)
    {
        unsigned long size;
        try
        {
            deserialize(size, in);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::string");
        }

        item.resize(size);
        if (size != 0)
        {
            in.read(&item[0], size);
            if (!in)
                throw std::runtime_error("error deserializing object of type std::string");
        }
    }

    // ----------------------------------------------------------------------------------------

    inline void serialize(const std::wstring& item, std::ostream& out)
    {
        const unsigned long size = static_cast<unsigned long>(item.size());
        try
        {
            serialize(size, out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type std::wstring");
        }

        for (unsigned long i = 0; i < item.size(); ++i)
            serialize(item[i], out);
        if (!out)
            throw std::runtime_error("error serializing object of type std::wstring");
    }

    inline void deserialize(std::wstring& item, std::istream& in)
    {
        unsigned long size;
        try
        {
            deserialize(size, in);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type std::wstring");
        }

        item.resize(size);
        for (unsigned long i = 0; i < item.size(); ++i)
            deserialize(item[i], in);

        if (!in)
            throw std::runtime_error("error deserializing object of type std::wstring");
    }

    // ----------------------------------------------------------------------------------------

    template <typename T>
    inline void serialize(const enumerable<T>& item, std::ostream& out)
    {
        try
        {
            item.reset();
            serialize(item.size(), out);
            while (item.move_next())
                serialize(item.element(), out);
            item.reset();
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type enumerable");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename domain, typename range>
    inline void serialize(const map_pair<domain, range>& item, std::ostream& out)
    {
        try
        {
            serialize(item.key(), out);
            serialize(item.value(), out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type map_pair");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename T, size_t length>
    inline void serialize(const T (&array)[length], std::ostream& out)
    {
        try
        {
            serialize(length, out);
            for (size_t i = 0; i < length; ++i)
                serialize(array[i], out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing a C style array");
        }
    }

    template <size_t length>
    inline void serialize(const char (&array)[length], std::ostream& out)
    {
        if (length != 0 && array[length - 1] == '\0')
        {
            // If this is a null terminated string then don't serialize the trailing null.
            // We do this so that the serialization format for C-strings is the same as
            // std::string.
            serialize(length - 1, out);
            out.write(array, length - 1);
            if (!out)
                throw std::runtime_error("error serializing a C-style string");
        }
        else
        {
            try
            {
                serialize(length, out);
            }
            catch (std::runtime_error& e)
            {
                throw std::runtime_error(std::string(e.what()) + "\n   while serializing a C style array");
            }
            if (length != 0)
                out.write(array, length);
            if (!out)
                throw std::runtime_error("error serializing a C-style string");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename T, size_t length>
    inline void deserialize(T (&array)[length], std::istream& in)
    {
        size_t size;
        try
        {
            deserialize(size, in);
            if (size == length)
            {
                for (size_t i = 0; i < length; ++i)
                    deserialize(array[i], in);
            }
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing a C style array");
        }

        if (size != length)
            throw std::runtime_error("error deserializing a C style array, lengths do not match");
    }

    template <size_t length>
    inline void deserialize(char (&array)[length], std::istream& in)
    {
        size_t size;
        try
        {
            deserialize(size, in);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing a C style array");
        }

        if (size == length)
        {
            in.read(array, size);
            if (!in)
                throw std::runtime_error("error deserializing a C-style array");
        }
        else if (size + 1 == length)
        {
            // In this case we are deserializing a C-style array so we need to add the null
            // terminator.
            in.read(array, size);
            array[size] = '\0';
            if (!in)
                throw std::runtime_error("error deserializing a C-style string");
        }
        else
        {
            throw std::runtime_error("error deserializing a C style array, lengths do not match");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename T, size_t N>
    inline void serialize(const std::array<T, N>& array, std::ostream& out)
    {
        typedef T c_array_type[N];
        serialize(*(const c_array_type*)array.data(), out);
    }

    template <typename T, size_t N>
    inline void deserialize(std::array<T, N>& array, std::istream& in)
    {
        typedef T c_array_type[N];
        deserialize(*(c_array_type*)array.data(), in);
    }

    template <typename T>
    inline void serialize(const std::array<T, 0>& /*array*/, std::ostream& out)
    {
        size_t N = 0;
        serialize(N, out);
    }

    template <typename T>
    inline void deserialize(std::array<T, 0>& /*array*/, std::istream& in)
    {
        size_t N;
        deserialize(N, in);
        if (N != 0)
        {
            std::ostringstream sout;
            sout << "Expected std::array of size 0 but found a size of " << N;
            throw std::runtime_error(sout.str());
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename T, typename deleter>
    void serialize(const std::unique_ptr<T, deleter>& item, std::ostream& out)
    {
        try
        {
            bool is_non_empty = item != nullptr;
            serialize(is_non_empty, out);
            if (is_non_empty)
                serialize(*item, out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing an object of type std::unique_ptr");
        }
    }

    template <typename T, typename deleter>
    void deserialize(std::unique_ptr<T, deleter>& item, std::istream& in)
    {
        try
        {
            // when deserializing unique_ptr, this is fresh state, so reset the pointers, even if item is non-empty
            bool is_non_empty;
            deserialize(is_non_empty, in);
            item.reset(
                is_non_empty ? new T() : nullptr);  // can't use make_unique since eon::node does not use C++14 as a minimum requirement.

            if (is_non_empty)
                deserialize(*item, in);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing an object of type std::unique_ptr");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename T>
    void serialize(const std::shared_ptr<T>& item, std::ostream& out)
    {
        try
        {
            bool is_non_empty = item != nullptr;
            serialize(is_non_empty, out);
            if (is_non_empty)
                serialize(*item, out);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing an object of type std::shared_ptr");
        }
    }

    template <typename T>
    void deserialize(std::shared_ptr<T>& item, std::istream& in)
    {
        try
        {
            // when deserializing shared_ptr, this is fresh state, so reset the pointers, even if item is non-empty
            bool is_non_empty;
            deserialize(is_non_empty, in);
            item = is_non_empty ? std::make_shared<T>() : nullptr;

            if (is_non_empty)
                deserialize(*item, in);
        }
        catch (std::runtime_error& e)
        {
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing an object of type std::shared_ptr");
        }
    }

    // ----------------------------------------------------------------------------------------

    class proxy_serialize
    {
    public:
        explicit proxy_serialize(const std::string& filename)
            : fout_optional_owning_ptr(new std::ofstream(filename.c_str(), std::ios::binary)),
              fout(*fout_optional_owning_ptr)
        {
            if (!fout)
                throw std::runtime_error("Unable to open " + filename + " for writing.");
        }

        explicit proxy_serialize(std::vector<char>& buf)
            : fout_optional_owning_ptr(new vectorstream(buf)),
              fout(*fout_optional_owning_ptr)
        {
        }

        explicit proxy_serialize(std::vector<int8_t>& buf)
            : fout_optional_owning_ptr(new vectorstream(buf)),
              fout(*fout_optional_owning_ptr)
        {
        }

        explicit proxy_serialize(std::vector<uint8_t>& buf)
            : fout_optional_owning_ptr(new vectorstream(buf)),
              fout(*fout_optional_owning_ptr)
        {
        }

        explicit proxy_serialize(std::ostream& ss)
            : fout_optional_owning_ptr(nullptr),
              fout(ss)
        {
        }

        template <typename T>
        inline proxy_serialize& operator<<(const T& item)
        {
            serialize(item, fout);
            return *this;
        }

    private:
        std::unique_ptr<std::ostream> fout_optional_owning_ptr;
        std::ostream&                 fout;
    };

    class proxy_deserialize
    {
    public:
        explicit proxy_deserialize(const std::string& filename_)
            : filename(filename_),
              fin_optional_owning_ptr(new std::ifstream(filename.c_str(), std::ios::binary)),
              fin(*fin_optional_owning_ptr)
        {
            if (!fin)
                throw std::runtime_error("Unable to open " + filename + " for reading.");
            init();
        }

        explicit proxy_deserialize(std::vector<char>& buf)
            : fin_optional_owning_ptr(new vectorstream(buf)),
              fin(*fin_optional_owning_ptr)
        {
            init();
        }

        explicit proxy_deserialize(std::vector<int8_t>& buf)
            : fin_optional_owning_ptr(new vectorstream(buf)),
              fin(*fin_optional_owning_ptr)
        {
            init();
        }

        explicit proxy_deserialize(std::vector<uint8_t>& buf)
            : fin_optional_owning_ptr(new vectorstream(buf)),
              fin(*fin_optional_owning_ptr)
        {
            init();
        }

        explicit proxy_deserialize(std::istream& ss)
            : fin_optional_owning_ptr(nullptr),
              fin(ss)
        {
            init();
        }

        template <typename T>
        inline proxy_deserialize& operator>>(T& item)
        {
            return doit(item);
        }

        template <typename T>
        inline proxy_deserialize& operator>>(ramdump_t<T>&& item)
        {
            return doit(std::move(item));
        }

    private:
        void init()
        {
            // read the file header into a buffer and then seek back to the start of the
            // file.
            fin.read(file_header, 4);
            fin.clear();
            fin.seekg(0);
        }

    private:
        template <typename T>
        inline proxy_deserialize& doit(T&& item)
        {
            try
            {
                if (fin.peek() == EOF)
                    throw std::runtime_error("No more objects were in the stream!");
                deserialize(std::forward<T>(item), fin);
            }
            catch (std::runtime_error& e)
            {
                std::string suffix;
                if (looks_like_a_compressed_file())
                    suffix = "\n *** THIS LOOKS LIKE A COMPRESSED FILE.  DID YOU FORGET TO DECOMPRESS IT? *** \n";

                const std::string stream_description = filename.empty() ? "stream" : "file '" + filename + "'";

                if (objects_read == 0)
                {
                    throw std::runtime_error("An error occurred while trying to read the first"
                                             " object from the "
                                             + stream_description + ".\nERROR: " + std::string(e.what()) + "\n" + suffix);
                }
                else if (objects_read == 1)
                {
                    throw std::runtime_error("An error occurred while trying to read the second"
                                             " object from the "
                                             + stream_description + ".\nERROR: " + std::string(e.what()) + "\n" + suffix);
                }
                else if (objects_read == 2)
                {
                    throw std::runtime_error("An error occurred while trying to read the third"
                                             " object from the "
                                             + stream_description + ".\nERROR: " + std::string(e.what()) + "\n" + suffix);
                }
                else
                {
                    throw std::runtime_error("An error occurred while trying to read the " + std::to_string(objects_read + 1)
                                             + "th object from the " + stream_description + ".\nERROR: " + std::string(e.what()) + "\n"
                                             + suffix);
                }
            }
            ++objects_read;
            return *this;
        }

        int                           objects_read = 0;
        const std::string             filename     = "";
        std::unique_ptr<std::istream> fin_optional_owning_ptr;
        std::istream&                 fin;

        // We don't need to look at the file header.  However, it's here because people
        // keep posting questions to the eon::node forums asking why they get file load errors.
        // Then it turns out that the problem is they have a compressed file that NEEDS TO
        // BE DECOMPRESSED by bzip2 or whatever and the reason they are getting
        // deserialization errors is because they didn't decompress the file.  So we are
        // going to check if this file looks like a compressed file and if so then emit an
        // error message telling them to unzip the file. :(
        char file_header[4] = { 0, 0, 0, 0 };

        bool looks_like_a_compressed_file() const
        {
            if (file_header[0] == 'B' && file_header[1] == 'Z' && file_header[2] == 'h' && ('0' <= file_header[3] && file_header[3] <= '9'))
            {
                return true;
            }

            return false;
        }
    };

    inline proxy_serialize serialize(const std::string& filename)
    {
        return proxy_serialize(filename);
    }
    inline proxy_serialize serialize(std::ostream& ss)
    {
        return proxy_serialize(ss);
    }
    inline proxy_serialize serialize(std::vector<char>& buf)
    {
        return proxy_serialize(buf);
    }
    inline proxy_serialize serialize(std::vector<int8_t>& buf)
    {
        return proxy_serialize(buf);
    }
    inline proxy_serialize serialize(std::vector<uint8_t>& buf)
    {
        return proxy_serialize(buf);
    }
    inline proxy_deserialize deserialize(const std::string& filename)
    {
        return proxy_deserialize(filename);
    }
    inline proxy_deserialize deserialize(std::istream& ss)
    {
        return proxy_deserialize(ss);
    }
    inline proxy_deserialize deserialize(std::vector<char>& buf)
    {
        return proxy_deserialize(buf);
    }
    inline proxy_deserialize deserialize(std::vector<int8_t>& buf)
    {
        return proxy_deserialize(buf);
    }
    inline proxy_deserialize deserialize(std::vector<uint8_t>& buf)
    {
        return proxy_deserialize(buf);
    }

    // ----------------------------------------------------------------------------------------
}  // namespace aoe::serialize

// forward declare the MessageLite object so we can reference it below.
namespace google::protobuf
{
    class MessageLite;
}


namespace aoe::serialize
{

    /*!A is_protocol_buffer
        This is a template that tells you if a type is a Google protocol buffer object.
    !*/

    template <typename T, typename U = void>
    struct is_protocol_buffer
    {
        static const bool value = false;
    };

    template <typename T>
    struct is_protocol_buffer<T, typename enable_if<std::is_convertible<T*, ::google::protobuf::MessageLite*>>::type>
    {
        static const bool value = true;
    };

    template <typename T>
    typename enable_if<is_protocol_buffer<T>>::type serialize(const T& item, std::ostream& out)
    {
        // Note that Google protocol buffer messages are not self delimiting
        // (see https://developers.google.com/protocol-buffers/docs/techniques)
        // This means they don't record their length or where they end, so we have
        // to record this information ourselves.  So we save the size as a little endian 32bit
        // integer prefixed onto the front of the message.

        byte_orderer bo;

        // serialize into temp string
        std::string temp;
        if (!item.SerializeToString(&temp))
            throw std::runtime_error("error while serializing a Google Protocol Buffer object. SerializeToString Failed");
        if (temp.size() > std::numeric_limits<uint32_t>::max())
            throw std::runtime_error("error while serializing a Google Protocol Buffer object, message too large.");

        // write temp to the output stream
        auto size = static_cast<uint32_t>(temp.size());
        bo.host_to_little(size);
        out.write((char*)&size, sizeof(size));
        out.write(temp.c_str(), temp.size());
    }

    template <class T>
    std::string type_name()
    {
        typedef typename std::remove_reference<T>::type TR;
        std::unique_ptr<char, void (*)(void*)>          own(abi::__cxa_demangle(typeid(TR).name(), nullptr, nullptr, nullptr), std::free);
        std::string                                     r = own != nullptr ? own.get() : typeid(TR).name();
        if (std::is_const<TR>::value)
            r += " const";
        if (std::is_volatile<TR>::value)
            r += " volatile";
        if (std::is_lvalue_reference<T>::value)
            r += "&";
        else if (std::is_rvalue_reference<T>::value)
            r += "&&";
        return r;
    }

    template <typename T>
    typename enable_if<is_protocol_buffer<T>>::type deserialize(T& item, std::istream& in)
    {
        // Note that Google protocol buffer messages are not self delimiting
        // (see https://developers.google.com/protocol-buffers/docs/techniques)
        // This means they don't record their length or where they end, so we have
        // to record this information ourselves.  So we save the size as a little endian 32bit
        // integer prefixed onto the front of the message.

        byte_orderer bo;

        uint32_t size = 0;
        // read the size
        in.read((char*)&size, sizeof(size));
        bo.little_to_host(size);
        if (!in || size == 0)
            throw std::runtime_error(
                "error while deserializing a Google Protocol Buffer object. size == 0, T is " + type_name<decltype(item)>());

        // read the bytes into temp
        std::string temp;
        temp.resize(size);
        in.read(&temp[0], size);

        // parse temp into item
        if (!in || !item.ParseFromString(temp))
        {
            throw std::runtime_error("error while deserializing a Google Protocol Buffer object. ParseFromString Failed");
        }
    }

    // ----------------------------------------------------------------------------------------

    inline void check_serialized_version(const std::string& expected_version, std::istream& in)
    {
        std::string version;
        deserialize(version, in);
        if (version != expected_version)
        {
            throw std::runtime_error("Unexpected version '" + version + "' found while deserializing object. Expected version to be '"
                                     + expected_version + "'.");
        }
    }

    // ----------------------------------------------------------------------------------------

    template <typename T>
    inline void serialize_these(std::ostream& out, const T& x)
    {
        using aoe::serialize::serialize;
        serialize(x, out);
    }

    template <typename T, typename... Rest>
    inline void serialize_these(std::ostream& out, const T& x, const Rest&... rest)
    {
        serialize_these(out, x);
        serialize_these(out, rest...);
    }

    template <typename T>
    inline void deserialize_these(std::istream& in, T& x)
    {
        using aoe::serialize::deserialize;
        deserialize(x, in);
    }

    template <typename T, typename... Rest>
    inline void deserialize_these(std::istream& in, T& x, Rest&... rest)
    {
        deserialize_these(in, x);
        deserialize_these(in, rest...);
    }

#define ESO_NODE_DEFINE_DEFAULT_SERIALIZATION(Type, ...)                                                                                   \
    void node_serialize_to(std::ostream& esoDefaultSer$_out) const                                                                         \
    {                                                                                                                                      \
        using aoe::serialize::serialize;                                                                                                   \
        using aoe::serialize::serialize_these;                                                                                             \
        try                                                                                                                                \
        {                                                                                                                                  \
            /* Write a version header so that if, at a later time, */                                                                      \
            /* you realize you need to change the serialization    */                                                                      \
            /* format you can identify which version of the format */                                                                      \
            /* you are encountering when reading old files.        */                                                                      \
            int esoDefaultSer$_version = 1;                                                                                                \
            serialize(esoDefaultSer$_version, esoDefaultSer$_out);                                                                         \
            serialize_these(esoDefaultSer$_out, __VA_ARGS__);                                                                              \
        }                                                                                                                                  \
        catch (std::runtime_error & e)                                                                                                     \
        {                                                                                                                                  \
            throw std::runtime_error(std::string(e.what()) + "\n   while serializing object of type " #Type);                              \
        }                                                                                                                                  \
    }                                                                                                                                      \
                                                                                                                                           \
    void node_deserialize_from(std::istream& esoDefaultSer$_in)                                                                            \
    {                                                                                                                                      \
        using aoe::serialize::deserialize;                                                                                                 \
        using aoe::serialize::deserialize_these;                                                                                           \
        try                                                                                                                                \
        {                                                                                                                                  \
            int esoDefaultSer$_version = 0;                                                                                                \
            deserialize(esoDefaultSer$_version, esoDefaultSer$_in);                                                                        \
            if (esoDefaultSer$_version != 1)                                                                                               \
                throw std::runtime_error("Unexpected version found while deserializing " #Type);                                           \
            deserialize_these(esoDefaultSer$_in, __VA_ARGS__);                                                                             \
        }                                                                                                                                  \
        catch (std::runtime_error & e)                                                                                                     \
        {                                                                                                                                  \
            throw std::runtime_error(std::string(e.what()) + "\n   while deserializing object of type " #Type);                            \
        }                                                                                                                                  \
    }                                                                                                                                      \
    inline friend void serialize(const Type& item, std::ostream& out)                                                                      \
    {                                                                                                                                      \
        item.node_serialize_to(out);                                                                                                       \
    }                                                                                                                                      \
    inline friend void deserialize(Type& item, std::istream& in)                                                                           \
    {                                                                                                                                      \
        item.node_deserialize_from(in);                                                                                                    \
    }
}  // namespace aoe::serialize
