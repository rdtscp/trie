cmake_minimum_required(VERSION 3.12)
set (CMAKE_CXX_STANDARD 17)

project(Trie)

add_library(Trie SHARED src/Trie.cpp src/TrieNode.cpp)
install(TARGETS Trie DESTINATION lib)
install(FILES include/trie include/Trie.h include/TrieNode.h DESTINATION include)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

enable_testing()
add_subdirectory(test)