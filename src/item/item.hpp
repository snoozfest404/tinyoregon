#pragma once

#include <string>
#include <nlohmann/json.hpp>

using nlohmann::json;
using std::string;

namespace item
{
    struct Item
    {
        string name;
        unsigned int weight = 0;
        unsigned int value = 0;
    };

    void from_json(const json& j, Item& i);
}