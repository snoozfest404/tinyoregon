#include "item.hpp"

#include <string>
#include <nlohmann/json.hpp>

using nlohmann::json;
using namespace item;

namespace item {
    void from_json(const json& j, Item& i) {
        j.at("name").get_to(i.name);
        j.at("weight").get_to(i.weight);
        j.at("value").get_to(i.value);
    }
}