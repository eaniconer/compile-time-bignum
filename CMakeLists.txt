cmake_minimum_required(VERSION 3.1)

set(VERSION 0.1.0)
message(STATUS "ct-bignum version ${VERSION}")

project(ct-bignum VERSION ${VERSION} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(test tests/test.cpp)