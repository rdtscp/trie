cmake_minimum_required(VERSION 3.12)
set (CMAKE_CXX_STANDARD 17)

project(Trie)
add_library(Trie SHARED src/Trie.cpp src/TrieNode.cpp)
set_target_properties(Trie PROPERTIES PUBLIC_HEADER include/Trie.h)


include(GNUInstallDirs)

install(TARGETS Trie
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

enable_testing()
add_subdirectory(test)