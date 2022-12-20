#pragma once

namespace entity {
    class Entity {
    protected:
        unsigned int max_health;
        unsigned int health;
        bool alive = true;
    public:
        unsigned int get_health() const { return this->health; };
        unsigned int get_max_health() const { return this->max_health; };
        bool is_alive() const { return this->alive; };
        void die();
        void hurt(unsigned int amount);
        void heal(unsigned int amount);
    };
}
