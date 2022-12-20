#include "settler.hpp"

using namespace settler;

Settler::Settler(const string &name, unsigned int max_health) {
    this->name = name;
    this->max_health = max_health;
    this->health = max_health;
}

void Settler::die() {
    this->alive = false;
    this->health = 0;
}

void Settler::heal(unsigned int amount) {
    if (!is_alive()) { return; }
    this->health = std::min(this->max_health, this->max_health+amount);
}

void Settler::hurt(unsigned int amount) {
    if (!is_alive()) { return; }
    unsigned int target_health = this->health-amount;
    if (target_health > 0) {
        this->health = target_health;
        return;
    }
    this->die();
}
