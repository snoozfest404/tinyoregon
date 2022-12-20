#include "item/item.hpp"
#include "game/game.hpp"

#include <string>
#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include <nlohmann/json.hpp>
#include <filesystem>
#include <fstream>
#include <map>
#include <vector>
#include <regex>

#define ITEMS_FILE          "items.json"
#define EVENTS_FILE         "events.json"
#define SETTLER_NAMES_FILE  "settler_names.txt"

#define PROMPT "> "
#define DIVIDER "---------"

using std::string;
using std::vector;
using std::map;
using nlohmann::json;

#define fs  std::filesystem
#define rgx std::regex

void print_help() {
    fmt::print("Usage: tinyoregon <data-dir-path>\n");
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        print_help();
        return 1;
    }

    fs::path data_dir_path(argv[1]);

    map<string, item::Item> item_pool;
    vector<string> settler_name_pool;

    // Construct absolute paths to data files.
    fs::path items_path = fs::canonical(data_dir_path / fs::path(ITEMS_FILE));
    fs::path events_path = fs::canonical(data_dir_path / fs::path(EVENTS_FILE));
    fs::path settler_names_path = fs::canonical(data_dir_path / fs::path(SETTLER_NAMES_FILE));

    // Read and parse items.
    std::ifstream items_f(items_path);
    json items_j = json::parse(items_f);
    item_pool = items_j;

    // TODO: Read and parse events.

    // Read and parse settler names.
    std::ifstream settler_names_f(settler_names_path);
    string line;
    while(getline(settler_names_f, line)) {
        settler_name_pool.push_back(line);
    }

    fmt::print(fg(fmt::terminal_color::green), "Welcome to the trail!\n");

    bool answer_invalid = false;

    game::Difficulty difficulty;
    while (true) {
        fmt::print("{}\n", DIVIDER);
        fmt::print("Please select a difficulty!\n");
        fmt::print("[1] Easy\n");
        fmt::print("[2] Normal\n");
        fmt::print("[3] Hard\n");
        fmt::print("\n");

        if (answer_invalid) {
            fmt::print(fg(fmt::terminal_color::yellow),
                "Please pick a valid option.\n");
        }

        string input;
        getline(std::cin, input);

        std::smatch res;
        if (!std::regex_match(input, res, rgx(R"(^[1-3]$)"))) {
            answer_invalid = true;
            continue;
        }

        int option = std::stoi(res.str(0));
        difficulty = static_cast<game::Difficulty>(option);
        break;
    }

    game::Game game_instance(difficulty, item_pool, settler_name_pool, 0);

    // Main game loop.
    while (game_instance.is_running()) {
        fmt::print(PROMPT);
        string input;
        getline(std::cin, input);
        game_instance.eval_input(input);
    }

    return 0;
}
