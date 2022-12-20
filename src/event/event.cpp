#include "event.hpp"

#include <nlohmann/json.hpp>

using nlohmann::json;

namespace event {
    void from_json(const json& j, Choice &c) {
        j.at("message").get_to(c.message);
        j.at("next_event_key").get_to(c.next_event_key);
        j.at("items").get_to(c.items);
    }

    void from_json(const json& j, Event &e) {
        j.at("message").get_to(e.message);
        j.at("choices").get_to(e.choices);
    }
}
