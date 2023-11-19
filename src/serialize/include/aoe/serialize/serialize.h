#pragma once

#include "aoe/serialize/serialize_base.h"

struct internal_msg
{
    char                               char_data{ 'a' };
    int8_t                             int8_data{ std::numeric_limits<int8_t>::max() };
    int16_t                            int16_data{ std::numeric_limits<int16_t>::max() };
    uint8_t                            uint8_data{ std::numeric_limits<uint8_t>::max() };
    uint16_t                           uint16_data{ std::numeric_limits<uint16_t>::max() };
    int32_t                            int32_data{ std::numeric_limits<int32_t>::max() };
    uint32_t                           uint32_data{ std::numeric_limits<uint32_t>::max() };
    int64_t                            int64_data{ std::numeric_limits<int64_t>::max() };
    uint64_t                           uint64_data{ std::numeric_limits<uint64_t>::max() };
    short                              short_data{ std::numeric_limits<short>::max() };
    std::string                        string_data{ "mr kanon" };
    std::vector<std::string>           vec_data;
    std::map<std::string, std::string> map_data;

    ESO_NODE_DEFINE_DEFAULT_SERIALIZATION(internal_msg, char_data, int8_data, int16_data, uint8_data, uint16_data, int32_data, uint32_data,
        int64_data, uint64_data, short_data, string_data, vec_data, map_data);
};


namespace aoe::serialize
{
    std::string getNodeVersion();
}