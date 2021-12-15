
set(TEST_NAME SampleTest)

file(GLOB_RECURSE sources "./**.cpp")

add_executable(${TEST_NAME} ${sources})

target_link_libraries(${TEST_NAME} PUBLIC
    gtest
    fastsim
    main_tests
)

add_test(
    NAME ${TEST_NAME}
    COMMAND ${TEST_NAME}
)
