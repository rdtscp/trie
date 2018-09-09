#include <string>
#include <vector>
#include <iostream>

#include "gtest/gtest.h"

#include "../include/Trie.h"

TEST(TrieTest, TestConstruction) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_TRUE(true);
}

TEST(TrieTest, TestValidWordExists) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_TRUE(dict.hasString("char"));
}

TEST(TrieTest, EmptyDictionary) {
	std::vector<std::string> words = { };
  Trie dict(words);

	ASSERT_TRUE(true);
}

TEST(TrieTest, DuplicateDictionary) {
	std::vector<std::string> words = { "test", "test" };
  Trie dict(words);

	ASSERT_TRUE(dict.hasString("test"));
}

// The fixture for testing class Project1. From google test primer.
class Test_Trie : public ::testing::Test {
	protected:

		Test_Trie() {
			// You can do set-up work for each test here.
		}

		// If the constructor and destructor are not enough for setting up
		// and cleaning up each test, you can define the following methods:
		virtual void SetUp() {
			// Code here will be called immediately after the constructor (right
			// before each test).
		}

		virtual void TearDown() {
			// Code here will be called immediately after each test (right
			// before the destructor).
		}

};