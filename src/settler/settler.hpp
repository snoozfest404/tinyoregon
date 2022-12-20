#pragma once

#include <string>

using std::string;

namespace settler {
    class Settler {
    private:
        string name;
        unsigned int max_health;
        unsigned int health;
        bool alive = true;
    public:
        Settler(const string &name, unsigned int max_health = 100);
        string get_name() { return this->name; };
        unsigned int get_health() { return this->health; };
        unsigned int get_max_health() { return this->max_health; };
        bool is_alive() { return this->alive; };
        void die();
        void hurt(unsigned int amount);
        void heal(unsigned int amount);
    };
}