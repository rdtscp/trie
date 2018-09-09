cmake_minimum_required(VERSION 3.12)
set (CMAKE_CXX_STANDARD 17)

project(Trie)
add_library(Trie SHARED src/Trie.cpp)
install(TARGETS Trie DESTINATION lib)
install(FILES include/Trie.h DESTINATION include)

enable_testing()
add_subdirectory(test)