#pragma once

namespace aoe::serialize
{
    // ----------------------------------------------------------------------------------------
    template <typename T>
    class enumerable
    {
    public:
        using type = T;

        inline virtual ~enumerable()                   = 0;
        virtual bool     at_start() const              = 0;
        virtual void     reset() const                 = 0;
        virtual bool     current_element_valid() const = 0;
        virtual const T& element() const               = 0;
        virtual T&       element()                     = 0;
        virtual bool     move_next() const             = 0;
        virtual size_t   size() const                  = 0;

    protected:
        enumerable& operator=(const enumerable&) = default;  // no assignment operator
    };

    // destructor does nothing
    template <typename T>
    enumerable<T>::~enumerable() = default;

    // ----------------------------------------------------------------------------------------

}  // namespace aoe::serialize
