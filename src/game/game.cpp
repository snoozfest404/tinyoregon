#include "game.hpp"

#include <string>
#include <regex>
#include <fmt/core.h>

#define rgx std::regex

using std::string;

using namespace game;

Game::Game(
    Difficulty difficulty,
    const map<string, item::Item> item_pool,
    const vector<string> settler_name_pool,
    unsigned long seed
) {
    this->difficulty = difficulty;
    this->item_pool = item_pool;
    this->settler_name_pool = settler_name_pool;
    this->rand_engine.seed(seed);
}

bool Game::is_running() {
    return this->running;
}

void Game::eval_input(const string &input) {
    if (input.length() == 0) {
        // Go on as usual and reprint the current message.
        return;
    }

    std::smatch res;        

    if (std::regex_match(input, rgx(R"(^exit$)"))) {
        this->running = false;
        return;
    } else if (std::regex_match(input, res, rgx(R"(^(help|\?)(\s+([a-z]+))?$)"))) {
        if (res.str(3) == "") {
            // Print general help message.
            return;
        }

        // This command should accept any lowercase word
        // and if not found should inform the player that
        // the requested command does not exist.
        string topic = res.str(3);

        // Print help message about the selected topic.
    } else if (std::regex_match(input, rgx(R"(^status$)"))) {
        // Print game status.
    } else if (std::regex_match(input, res, rgx(R"(^pick(\s+(\d+))?$)"))) {
        if (res.str(2) == "") {
            fmt::print("Usage: pick <option-number>\n");
            return;
        }
        int option = std::stoi(res.str(2));
        // Handle the chose option.
    } else {
        fmt::print("Unknown command: {}\n", input);
    }
}