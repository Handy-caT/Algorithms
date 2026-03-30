include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

file(GLOB SOURCE_FILES *.cpp)

add_executable(reverse_words_test ${SOURCE_FILES})

target_link_libraries(reverse_words_test
        PRIVATE
        GTest::GTest
        custom_functions
        )


add_test(reverse_words_gtest reverse_words_test)