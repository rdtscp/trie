cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)
option(test "Build all tests." OFF) # Makes boolean 'test' available.

project(Trie)
add_library(Trie SHARED src/Trie.cpp)
install(TARGETS Trie DESTINATION lib)
install(FILES include/Trie.h DESTINATION include)

add_subdirectory(test)