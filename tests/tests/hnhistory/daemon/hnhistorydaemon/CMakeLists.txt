
set(TEST_NAME HNHistoryDaemon)

file(GLOB_RECURSE sources "./src/**.cpp")

add_executable(${TEST_NAME} ${sources})

find_package(Qt5 COMPONENTS Core REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_link_libraries(${TEST_NAME} PUBLIC
    gtest
    test_main
    Qt5::Core
)

add_test(
    NAME ${TEST_NAME}
    COMMAND ${TEST_NAME}
)

set_tests_properties(${TEST_NAME} PROPERTIES TIMEOUT 30)