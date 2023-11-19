#pragma once

#include <cmath>
#include <limits>

#include "aoe/serialize/enable_if.h"

namespace aoe::serialize
{
    template <long x, long y, typename enabled = void>
    struct tmin
    {
        const static long value = x;
    };
    template <long x, long y>
    struct tmin<x, y, typename enable_if_c<(y < x)>::type>
    {
        const static long value = y;
    };

    struct float_details
    {
        float_details(int64_t man, int16_t exp)
            : mantissa(man),
              exponent(exp)
        {
        }
        float_details()
            : mantissa(0),
              exponent(0)
        {
        }

        float_details(const double& val)
        {
            *this = val;
        }
        float_details(const float& val)
        {
            *this = val;
        }
        float_details(const long double& val)
        {
            *this = val;
        }

        float_details& operator=(const double& val)
        {
            convert_from_T(val);
            return *this;
        }
        float_details& operator=(const float& val)
        {
            convert_from_T(val);
            return *this;
        }
        float_details& operator=(const long double& val)
        {
            convert_from_T(val);
            return *this;
        }

        operator double() const
        {
            return convert_to_T<double>();
        }
        operator float() const
        {
            return convert_to_T<float>();
        }
        operator long double() const
        {
            return convert_to_T<long double>();
        }

        constexpr const static int16_t is_inf  = 32000;
        constexpr const static int16_t is_ninf = 32001;
        constexpr const static int16_t is_nan  = 32002;

        int64_t mantissa;
        int16_t exponent;

    private:
        template <typename T>
        void convert_from_T(const T& val)
        {
            mantissa         = 0;
            const int digits = aoe::serialize::tmin<std::numeric_limits<T>::digits, 63>::value;

            if (val == std::numeric_limits<T>::infinity())
            {
                exponent = is_inf;
            }
            else if (val == -std::numeric_limits<T>::infinity())
            {
                exponent = is_ninf;
            }
            else if (val < std::numeric_limits<T>::infinity())
            {
                int exp;
                mantissa = static_cast<int64_t>(std::frexp(val, &exp) * (((uint64_t)1) << digits));
                exponent = exp - digits;

                // Compact the representation a bit by shifting off any low order bytes
                // which are zero in the mantissa.  This makes the numbers in mantissa and
                // exponent generally smaller which can make serialization and other things
                // more efficient in some cases.
                for (int i = 0; i < 8 && ((mantissa & 0xFF) == 0); ++i)
                {
                    mantissa >>= 8;
                    exponent += 8;
                }
            }
            else
            {
                exponent = is_nan;
            }
        }

        template <typename T>
        T convert_to_T() const
        {
            if (exponent < is_inf)
                return std::ldexp((T)mantissa, exponent);
            else if (exponent == is_inf)
                return std::numeric_limits<T>::infinity();
            else if (exponent == is_ninf)
                return -std::numeric_limits<T>::infinity();
            else
                return std::numeric_limits<T>::quiet_NaN();
        }
    };

}  // namespace aoe::serialize
