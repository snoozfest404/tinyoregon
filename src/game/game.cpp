#include "game.hpp"

#include <string>
#include <regex>
#include <fmt/core.h>
#include <fmt/color.h>

#define rgx std::regex

using std::string;

using namespace game;

Game::Game(
    Difficulty difficulty,
    const settler::Caravan &player_caravan,
    const map<string, item::Item> &item_pool,
    const vector<string> &settler_name_pool,
    unsigned long seed
) : player_caravan(player_caravan) {
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
        const string general_help_msg =
            "Available commands are:\n"
            "  status   Show the current game status\n"
            "  pick     Pick an option\n"
            "  help     Show general or command specific help message\n"
            "  exit     Exit the game\n";

        if (res.str(3) == "") {
            fmt::print(general_help_msg);
            return;
        }

        // This command should accept any lowercase word
        // and if not found should inform the player that
        // the requested command does not exist.
        string topic = res.str(3);

        // Print help message about the selected topic.
    } else if (std::regex_match(input, rgx(R"(^status$)"))) {
        fmt::print(fmt::emphasis::underline, "Caravan:\n");
        fmt::print("\n");

        fmt::print("Health: {} / {}\n", player_caravan.get_health(),
            player_caravan.get_max_health());
        fmt::print("\n");

        fmt::print(fmt::emphasis::underline, "Settlers:\n");
        fmt::print("\n");

        for (const auto &s : player_caravan.get_settlers()) {
            fmt::print("Name:\t{}\n", s.get_name());
            fmt::print("Health:\t{} / {}\n", s.get_health(), s.get_max_health());
            fmt::print("\n");
        }
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