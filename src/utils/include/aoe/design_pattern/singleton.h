#pragma once

#include <cstdint>

namespace aoe::design_pattrn {

    template<typename T, long N>
    class IAutoLaunch;

    template<typename T, int64_t N = 0>
    class Singleton {
    public:
        inline static T &ref() {
            static T instace_;
            return instace_;
        }

        inline static T *ptr() {
            return &ref();
        }
    };
}