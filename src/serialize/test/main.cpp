#include <iostream>

#include "aoe/serialize/serialize.h"


int main()
{
    std::cout << "NODE VERSION = " << aoe::serialize::getNodeVersion() << std::endl;

    internal_msg msg;
    msg.vec_data.emplace_back("hello");
    msg.vec_data.emplace_back("world");
    msg.map_data.try_emplace("kanon", "2222");
    msg.map_data.try_emplace("JSON", "2938");

    // 将一个结构体序列化为 ostringstream.
    std::ostringstream package_out;
    serialize(msg, package_out);

    std::cout << "size = " << package_out.str().size() << std::endl;

    // 将一个istringstream 反序列化为 msg 结构体
    internal_msg       outmsg;
    std::istringstream sin(package_out.str());
    deserialize(outmsg, sin);

    std::cout << "int8_data    = " << outmsg.int8_data << std::endl;
    std::cout << "int8_data    = " << outmsg.int8_data << std::endl;
    std::cout << "int16_data   = " << outmsg.int16_data << std::endl;
    std::cout << "int32_data   = " << outmsg.int32_data << std::endl;
    std::cout << "int64_data   = " << outmsg.int64_data << std::endl;

    std::cout << "uint8_data   = " << outmsg.uint8_data << std::endl;
    std::cout << "uint16_datat = " << outmsg.uint16_data << std::endl;
    std::cout << "uint32_data  = " << outmsg.uint32_data << std::endl;
    std::cout << "uint64_data  = " << outmsg.uint64_data << std::endl;


    std::cout << "char_data    = " << outmsg.char_data << std::endl;
    std::cout << "short_data   = " << outmsg.short_data << std::endl;
    std::cout << "string_data  = " << outmsg.string_data << std::endl;

    std::string out;
    for (auto& item : outmsg.vec_data)
    {
        out.append(item);
        out.append(" ");
    }

    std::cout << "data         = " << out << std::endl;

    for (auto& [k, v] : outmsg.map_data)
    {
        std::cout << "Key = " << k << " value = " << v << std::endl;
    }

    return 0;
}
