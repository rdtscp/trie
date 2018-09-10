#include <string>
#include <vector>
#include <iostream>

#include "gtest/gtest.h"

#include "../include/Trie.h"

/* Assert that a Default Trie Constructs without error. */
TEST(TrieTest, TestDefaultConstruction) {
  Trie dict;

	ASSERT_TRUE(true);
}

/* Assert that a normal Trie Constructs without error. */
TEST(TrieTest, TestNormalConstruction) {
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

	ASSERT_TRUE(dict.find("test"));
}

/* Test a Valid Word Exists. */
TEST(TrieTest, ValidWordHasEntry) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_TRUE(dict.find("char"));
}

/* Test an Invalid Word Exists */
TEST(TrieTest, InvalidWordHasEntry) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_FALSE(dict.find("bli"));
}

/* Test an empty Word Exists */
TEST(TrieTest, EmptyWordfind) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_TRUE(dict.find(""));
}

/* Test a Valid Prefix Exists */
TEST(TrieTest, ValidPrefixHasPrefix) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_TRUE(dict.has_prefix("cha"));
}

/* Test an Invalid Prefix Exists */
TEST(TrieTest, InvalidPrefixHasPrefix) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_FALSE(dict.has_prefix("bli"));
}

/* Test an empty Prefix Exists */
TEST(TrieTest, EmptyPrefixHasPrefix) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_TRUE(dict.has_prefix(""));
}

/* Test Inserting a word into an existing Trie. */
TEST(TrieTest, ExistingTrieInsertWord) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict(words);

	ASSERT_FALSE(dict.find("table"));

	dict.insert("table");

	ASSERT_TRUE(dict.find("table"));
}

/* Test Inserting into a Default Constructed Trie. */
TEST(TrieTest, InsertDefaultConstructed) {
	Trie dict;

	ASSERT_FALSE(dict.find("table"));

	dict.insert("table");

	ASSERT_TRUE(dict.find("table"));
}

/* Test Copy Constructor Works */
TEST(TrieTest, CopyConstructor) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  Trie dict1(words);

	ASSERT_TRUE(dict1.find("char"));

	Trie dict2(dict1);

	ASSERT_TRUE(dict1.find("char"));
	ASSERT_TRUE(dict2.find("char"));
}

/* Test =operator normal usage. */
TEST(TrieTest, EqualOperatorCopiesNormal) {
	std::vector<std::string> words = { "char" };
  Trie dict1(words);

	ASSERT_TRUE(dict1.find("char"));

	Trie dict2 = dict1;

	ASSERT_TRUE(dict1.find("char"));
	ASSERT_TRUE(dict2.find("char"));
} 

/* Test =operator edge cases. */
TEST(TrieTest, EqualOperatorCopiesEdge) {
	std::vector<std::string> words = {};
  Trie defaultDict;
  Trie emptyDict(words);

	ASSERT_FALSE(defaultDict.find("word"));
	ASSERT_FALSE(emptyDict.find("word"));

	Trie testDict1 = defaultDict;
	Trie testDict2 = emptyDict;

	ASSERT_FALSE(testDict1.find("word"));
	ASSERT_FALSE(testDict2.find("word"));
} 

/* Test when Inefficient Construction is Used. */
TEST(TrieTest, InefficentConstruction) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
	Trie dict = Trie(words);

	ASSERT_TRUE(dict.find("char"));
}

/* Test that inserting to a Copy doesn't effect the original. */
TEST(TrieTest, InsertWordToCopy) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
	Trie dictOne = Trie(words);

	ASSERT_TRUE(dictOne.find("char"));

	Trie dictTwo   = dictOne;
	Trie dictThree(dictTwo);

	ASSERT_TRUE(dictTwo.find("char"));
	ASSERT_TRUE(dictThree.find("char"));

	dictTwo.insert("table");

	ASSERT_FALSE(dictOne.find("table"));
	ASSERT_TRUE(dictTwo.find("table"));
	ASSERT_FALSE(dictThree.find("table"));
}

/* Test that every word inserted matches its prefixes. */
TEST(TrieTest, InsertedWordsHasPrefix) {
	Trie dict;
	std::string test = "VeryLongStringWhichHasLotsOfPrefixes!";
	dict.insert(test);

	for (int i = 0; i < test.length(); i++) {
		std::string currPrefix = test.substr(0, i);
		ASSERT_TRUE(dict.has_prefix(currPrefix));
	}
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