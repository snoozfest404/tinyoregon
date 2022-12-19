cmake_minimum_required(VERSION 3.16)
project(
    tinyoregon
    VERSION     0.1.0
    LANGUAGES   CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)

include(FetchContent)
FetchContent_Declare(
    jsonlib
    GIT_REPOSITORY  https://github.com/nlohmann/json
    GIT_TAG         bc889afb4c5bf1c0d8ee29ef35eaaf4c8bef8a5d # v3.11.2
)
FetchContent_Declare(
    fmtlib
    GIT_REPOSITORY  https://github.com/fmtlib/fmt
    GIT_TAG         a33701196adfad74917046096bf5a2aa0ab0bb50 # v9.1.0
)
FetchContent_MakeAvailable(
    jsonlib
    fmtlib
)

add_subdirectory(src)
add_subdirectory(tests)
