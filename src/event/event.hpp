#pragma once

#include <string>
#include <vector>
#include <map>
#include <nlohmann/json.hpp>

using nlohmann::json;

using std::string;
using std::vector;
using std::map;

namespace event {
    struct Choice {
        string message;
        string next_event_key;
        map<string, int> items;
    };

    void from_json(const json& j, Choice &c);

    struct Event {
        string message;
        vector<Choice> choices;
    };

    void from_json(const json& j, Event &c);
}
