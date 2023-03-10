#pragma once

#include "../item/item.hpp"
#include "../settler/caravan.hpp"

#include <vector>
#include <map>
#include <random>

using std::vector;
using std::map;

namespace game {
    enum class Difficulty : unsigned int {
        Easy,
        Normal,
        Hard,
    };

    class Game {
    private:
        bool running = true;
        Difficulty difficulty;
        settler::Caravan player_caravan;
        std::default_random_engine rand_engine;
        map<string, item::Item> item_pool;
        vector<string> settler_name_pool;
    public:
        Game(
            Difficulty difficulty,
            const settler::Caravan &player_caravan,
            const map<string, item::Item> &item_pool,
            const vector<string> &settler_name_pool,
            unsigned long seed
        );
        void eval_input(const string &input);
        bool is_running();
    };
}