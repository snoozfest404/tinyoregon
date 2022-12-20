#pragma once

#include "settler.hpp"
#include "../entity/entity.hpp"

#include <vector>

using std::vector;

namespace settler {
    class Caravan : protected entity::Entity {
    private:
        vector<Settler> settlers;
    public:
        Caravan(const vector<Settler> &settlers, unsigned int max_health = 100);
        const vector<Settler> & get_settlers() const { return this->settlers; };
    };
}
