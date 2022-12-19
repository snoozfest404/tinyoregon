#[[
FetchContent_Declare(
   googletest
   GIT_REPOSITORY  https://github.com/google/googletest
   GIT_TAG         15460959cbbfa20e66ef0b5ab497367e47fc0a04 # v1.12.0
)
FetchContent_MakeAvailable(googletest)

add_executable(
    tests
)

target_link_libraries(
    tests
    PRIVATE GTest::gtest_main
)

target_include_directories(
    tests
    PRIVATE ${CMAKE_SOURCE_DIR}/src
)

include(CTest)
include(GoogleTest)
gtest_discover_tests(tests)
]]
