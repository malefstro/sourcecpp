cmake_minimum_required(VERSION 3.10)
project(sourcecpp)

set(CMAKE_CXX_STANDARD 17)

set(CATCH2_INC "${CMAKE_SOURCE_DIR}/thirdparties/catch2")
set(SRC_INC "${CMAKE_SOURCE_DIR}/src")

add_executable(sourcecpp main.cpp test/std_optional_examples.cpp src/var_utils_01.cpp src/var_utils_01.hpp src/common/Person.cpp src/common/Person.hpp test/std_variant_simples.cpp)

target_include_directories(sourcecpp PUBLIC ${CATCH2_INC} ${SRC_INC})


