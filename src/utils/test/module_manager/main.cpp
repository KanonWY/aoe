#include <iostream>
#include "aoe/self_start/manager.h"
#include "aoe/self_start/module.h"
#include "aoe/self_start/self_start.h"
#include "aoe/this_process/this_process.h"


// define a IModule class
class MyClass: public aoe::self_start::IModule<MyClass> {
public:
    MyClass() {
        std::cout << "自定义模块构造" << std::endl;
    }

protected:
    aoe::self_start::Policy getSelfStartPolicy() override {
        aoe::self_start::Policy policy;
        policy.name = "MyClass";
        return policy;
    }
    bool onStart(IModule* self) override {
        std::cout << "MyClass start" << std::endl;
        std::cout << "cwd: " << aoe::this_process::cwd() << std::endl;

        int    argc = aoe::this_process::argc();
        char** argv = aoe::this_process::argv();
        return true;
    }

    void onClose(IModule* self) override {
        std::cout << "MyClass close" << std::endl;
    }

private:
    static std::byte helper_;
};


// aoe::design_pattrn::Singleton<aoe::self_start::Manager, 0>::ref().addModule(aoe::design_pattrn::Singleton<MyClass, 0>::ref());

static std::byte init_ = []() -> std::byte {
    aoe::design_pattrn::Singleton<aoe::self_start::Manager, 0>::ref().addModule(
    aoe::design_pattrn::Singleton<MyClass, 0>::ref());
    return {};
}();


int main() {
    std::cout << "Before Main" << std::endl;

    aoe::self_start::setup();

    aoe::self_start::shutdown();
    return 0;
}