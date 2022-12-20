#pragma once

#include "../item/item.hpp"

#include <vector>
#include <map>
#include <random>

using std::vector;
using std::map;

namespace game {
    class Game {
    private:
        bool running = true;
        std::default_random_engine rand_engine;
        map<string, item::Item> item_pool;
        vector<string> settler_name_pool;
    public:
        Game(
            const map<string, item::Item> item_pool,
            const vector<string> settler_name_pool,
            int seed
        );
        void eval_input(const string &input);
        bool is_running();
    };

    enum class Difficulty : unsigned int {
        Easy,
        Normal,
        Hard,
    };
}