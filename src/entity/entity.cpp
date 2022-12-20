#include "entity.hpp"

#include <algorithm>

using namespace entity;

Entity::Entity(unsigned int max_health, unsigned int health) {
    this->max_health = max_health;
    this->health = health;
}

Entity::Entity(unsigned int max_health)
    : Entity(max_health, max_health) {}

void Entity::die() {
    this->alive = false;
    this->health = 0;
}

void Entity::heal(unsigned int amount) {
    if (!is_alive()) { return; }
    this->health = std::min(this->max_health, this->max_health+amount);
}

void Entity::hurt(unsigned int amount) {
    if (!is_alive()) { return; }
    unsigned int target_health = this->health-amount;
    if (target_health > 0) {
        this->health = target_health;
        return;
    }
    this->die();
}
