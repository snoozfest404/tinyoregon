#include "settler.hpp"

using namespace settler;

Settler::Settler(const string &name, unsigned int max_health) {
    this->name = name;
    this->max_health = max_health;
    this->health = max_health;
}
