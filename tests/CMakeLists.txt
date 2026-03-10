find_package(GTest REQUIRED)

enable_testing()

add_executable(TaskList_Tests
    test_single_list.cpp
    test_save_file.cpp
)

target_link_libraries(TaskList_Tests
    PRIVATE
        Qt::Core
        Qt::Widgets
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(TaskList_Tests)
