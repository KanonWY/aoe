#pragma once

namespace aoe::serialize
{

    // ----------------------------------------------------------------------------------------

    template <typename T1, typename T2>
    class map_pair
    {
    public:
        using key_type   = T1;
        using value_type = T2;

        virtual ~map_pair()             = 0;
        virtual const T1& key() const   = 0;
        virtual const T2& value() const = 0;
        virtual T2&       value()       = 0;

    protected:
        // restricted functions
        map_pair<T1, T2>& operator=(const map_pair<T1, T2>&) = default;  // no assignment operator
    };

    // destructor does nothing
    template <typename T1, typename T2>
    map_pair<T1, T2>::~map_pair() = default;

    // ----------------------------------------------------------------------------------------

}  // namespace aoe::serialize
