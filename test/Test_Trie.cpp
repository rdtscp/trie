#include <string>
#include <vector>
#include <iostream>

#include "gtest/gtest.h"

#include "../include/Trie.h"

/* Assert that a normal Trie Constructs without error. */
TEST(TrieTest, TestConstruction) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_TRUE(true);
}

/* Test Constructing an empty Trie */
TEST(TrieTest, EmptyDictionary) {
	std::vector<std::string> words = { };
  Trie dict(words);

	ASSERT_TRUE(true);
}

/* Test Constructing a Dictionary with a Duplicate Word */
TEST(TrieTest, DuplicateDictionary) {
	std::vector<std::string> words = { "test", "test" };
  Trie dict(words);

	ASSERT_TRUE(dict.hasString("test"));
}

/* Test a Valid Word Exists. */
TEST(TrieTest, ValidWordHasEntry) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_TRUE(dict.hasString("char"));
}

/* Test an Invalid Word Exists */
TEST(TrieTest, InvalidWordHasEntry) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_FALSE(dict.hasString("bli"));
}

/* Test an empty Word Exists */
TEST(TrieTest, EmptyWordHasString) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_TRUE(dict.hasString(""));
}

/* Test a Valid Prefix Exists */
TEST(TrieTest, ValidPrefixHasPrefix) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_TRUE(dict.hasPrefix("cha"));
}

/* Test an Invalid Prefix Exists */
TEST(TrieTest, InvalidPrefixHasPrefix) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_FALSE(dict.hasPrefix("bli"));
}

/* Test an empty Prefix Exists */
TEST(TrieTest, EmptyPrefixHasPrefix) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_TRUE(dict.hasPrefix(""));
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