#include "settler.hpp"
#include "../entity/entity.hpp"

using namespace settler;

Settler::Settler(
    const string &name,
    unsigned int max_health
) : Settler(name, max_health, max_health) {}

Settler::Settler(
    const string &name,
    unsigned int max_health,
    unsigned int health
) : Entity(max_health, health) {
    this->name = name;
}
