#include "caravan.hpp"
#include "settler.hpp"
#include "../entity/entity.hpp"

#include <vector>

using std::vector;

using namespace settler;

Caravan::Caravan(
    const vector<Settler> &settlers,
    unsigned int max_health,
    unsigned int health
) : Entity(max_health, health) {
    this->settlers = settlers;
}

Caravan::Caravan(
    const vector<Settler> &settlers,
    unsigned int max_health
) : Caravan(settlers, max_health, max_health) {}

Caravan::Caravan(
    const Caravan &c
) : Entity(c.max_health, c.health) {
    this->settlers = c.settlers;
    this->alive = c.alive;
}

Caravan & Caravan::operator=(const Caravan &c) {
    if (this == &c) {
        return *this;
    }

    *this = c;
    return *this;
}
