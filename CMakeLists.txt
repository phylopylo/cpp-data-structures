cmake_minimum_required(VERSION 4.1.6)
project("C++ Data Structures" LANGUAGES CXX)


add_executable(main main.cpp)

target_compile_features(main PRIVATE cxx_std_23)
target_compile_options(main PRIVATE -g -Wall -Wextra -fsanitize=address,undefined)
target_link_options(main PRIVATE -fsanitize=address,undefined)
