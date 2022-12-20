add_executable(
    tinyoregon
    main.cpp
    item/item.hpp
    item/item.cpp
    game/game.hpp
    game/game.cpp
    settler/settler.hpp
    settler/settler.cpp
    settler/caravan.hpp
    settler/caravan.cpp
    entity/entity.hpp
    entity/entity.cpp
)

target_link_libraries(
    tinyoregon
    PRIVATE nlohmann_json::nlohmann_json
    PRIVATE fmt::fmt
)