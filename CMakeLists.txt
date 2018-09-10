cmake_minimum_required(VERSION 3.9.2)
set (CMAKE_CXX_STANDARD 17)

project(Trie)

IF(CMAKE_BUILD_TYPE MATCHES Release)
  message(" --- Building in Release Mode ---")
  add_library(Trie SHARED src/Trie.cpp src/TrieNode.cpp)
  install(
    TARGETS Trie
    DESTINATION lib
  )
  install(
    FILES include/trie include/Trie.h include/TrieNode.h
    DESTINATION include
  )
ENDIF(CMAKE_BUILD_TYPE MATCHES Release)

IF(CMAKE_BUILD_TYPE MATCHES Debug)
  message(" --- Building in Debug Mode ---")
  add_library(Trie SHARED src/Trie.cpp src/TrieNode.cpp)
  install(
    TARGETS Trie
    DESTINATION lib
  )
  install(
    FILES include/trie include/Trie.h include/TrieNode.h
    DESTINATION include
  )
  enable_testing()
  add_subdirectory(test)
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)
