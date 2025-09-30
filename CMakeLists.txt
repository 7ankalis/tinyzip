cmake_minimum_required(VERSION 3.10)
project(tinyzip)

set(CMAKE_CXX_STANDARD 14)

find_package(ZLIB REQUIRED)

include_directories(include)
include_directories(src)

add_executable(tinyzip
        include/compress.h
        include/decompress.h
        include/optimize.h
        src/compress.cpp
        src/decompress.cpp
        src/main.cpp
        src/optimize.cpp
        LICENSE
        README.md
        SECURITY.md)

target_link_libraries(tinyzip PRIVATE ZLIB::ZLIB)

# Tests
enable_testing()

add_executable(tz_test_roundtrip
        tests/test_roundtrip.cpp
        src/compress.cpp
        src/decompress.cpp)
target_link_libraries(tz_test_roundtrip PRIVATE ZLIB::ZLIB)
add_test(NAME roundtrip COMMAND tz_test_roundtrip)

add_executable(tz_test_empty
        tests/test_empty.cpp
        src/compress.cpp
        src/decompress.cpp)
target_link_libraries(tz_test_empty PRIVATE ZLIB::ZLIB)
add_test(NAME empty_roundtrip COMMAND tz_test_empty)

# CLI tests that exercise the tinyzip binary
add_test(NAME cli_roundtrip
         COMMAND bash ${CMAKE_SOURCE_DIR}/tests/test_cli_roundtrip.sh ${CMAKE_BINARY_DIR})
add_test(NAME cli_empty
         COMMAND bash ${CMAKE_SOURCE_DIR}/tests/test_cli_empty.sh ${CMAKE_BINARY_DIR})
