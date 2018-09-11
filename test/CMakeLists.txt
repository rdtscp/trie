enable_testing()

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/googletest/include")

ADD_EXECUTABLE(runTrieUnitTests Test_Trie.cpp main.cpp)

TARGET_LINK_LIBRARIES(runTrieUnitTests
    trie
    libgtest
    libgmock
)

add_test(TrieUnitTests runTrieUnitTests)
