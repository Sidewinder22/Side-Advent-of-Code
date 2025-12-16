set(YEAR 2025)
set(TARGET 1)

set(LIB dial)
set(TESTS 2025_1_Dial_tests)

set(PART_1 ${YEAR}_${TARGET}_part_1)

add_library(${LIB} STATIC Dial.cpp)

add_executable(${PART_1} part_1.cpp)
target_link_libraries(${PART_1} PRIVATE tools dial)

add_executable(
    ${TESTS}    
    DialTest.cpp
)

target_link_libraries(${TESTS}
    ${LIB}
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${TESTS})
