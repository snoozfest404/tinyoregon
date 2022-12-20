#pragma once

#include "../entity/entity.hpp"

#include <string>

using std::string;

namespace settler {
    class Settler : protected entity::Entity {
    private:
        string name;
    public:
        Settler(const string &name, unsigned int max_health = 100);
        string get_name() const { return this->name; };
    };
}
