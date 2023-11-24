#include <atomic>
#include <mutex>

namespace aoe::test {
class Static_Singleton {
public:
    Static_Singleton(const Static_Singleton&)            = delete;
    Static_Singleton& operator=(const Static_Singleton&) = delete;
    Static_Singleton(Static_Singleton&&)                 = delete;
    Static_Singleton& operator=(Static_Singleton&)       = delete;

    static Static_Singleton& Instance() {
        static Static_Singleton singleton;
        return singleton;
    }
private:
    Static_Singleton() = default;
};
} // namespace aoe::test