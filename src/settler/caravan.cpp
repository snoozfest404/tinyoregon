#include "caravan.hpp"

#include <vector>

using std::vector;

using namespace settler;

Caravan::Caravan(const vector<Settler> &settlers, unsigned int max_health) {
    this->settlers = settlers;
    this->max_health = max_health;
    this->health = max_health;
}
