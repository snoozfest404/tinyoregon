#include "item/item.hpp"

#include <string>
#include <iostream>
#include <fmt/core.h>
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

using std::string;
using std::vector;
using std::map;
using nlohmann::json;

#define fs  std::filesystem
#define rgx std::regex

void print_help() {
    fmt::print("Usage: tinyoregon <data-dir-path>\n");
}

// TODO: Relocate to a dedicated game state object.
map<string, item::Item> item_pool;
vector<string> settler_name_pool;

void read_game_data(fs::path data_dir_path) {
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
}

// TODO: Receive a game state object to be modified.
// Alternatively integrate into the class itself.
void evaluate(const string &input) {
    if (input.length() == 0) {
        // Go on as usual and reprint the current message.
        return;
    }

    std::smatch res;        

    if (std::regex_match(input, rgx(R"(^exit$)"))) {
        // Exit the game.
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

int main(int argc, char **argv)
{
    if (argc < 2) {
        print_help();
        return 1;
    }

    fs::path data_dir_path(argv[1]);
    // Handle invalid path or missing files and exit gracefully.
    read_game_data(data_dir_path);

    // Main game loop.
    while (true) {
        fmt::print(PROMPT);
        string input;
        getline(std::cin, input);
        evaluate(input);
        fmt::print("\n");
    }

    return 0;
}
