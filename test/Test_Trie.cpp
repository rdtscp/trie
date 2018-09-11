#include <string>
#include <vector>
#include <iostream>

#include "gtest/gtest.h"

#include "../include/trie.h"

using namespace ads;

/* Assert that a Default trie Constructs without error. */
TEST(trieTest, DefaultConstruction) {
  trie dict;

	ASSERT_TRUE(true);
}

/* Assert that a normal trie Constructs without error. */
TEST(trieTest, NormalConstruction) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  trie dict(words);

	ASSERT_TRUE(true);
}

TEST(trieTest, InitializerListConstruction) {
  trie dict = { "char", "chai", "chair", "ant" };

	ASSERT_TRUE(dict.find("char"));
}

/* Test that copying/assigning to itself works. */
TEST(trieTest, CopyToSelf) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  trie dict(words);

	ASSERT_TRUE(dict.find("char"));

	dict = dict;

	ASSERT_TRUE(dict.find("char"));
}

/* Test Constructing an empty trie */
TEST(trieTest, EmptyDictionary) {
	std::vector<std::string> words = { };
  trie dict(words);

	ASSERT_TRUE(true);
}

/* Test Constructing a Dictionary with a Duplicate Word */
TEST(trieTest, DuplicateDictionary) {
	std::vector<std::string> words = { "test", "test" };
  trie dict(words);

	ASSERT_TRUE(dict.find("test"));
}

/* Test a Valid Word Exists. */
TEST(trieTest, ValidWordFind) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  trie dict(words);

	ASSERT_TRUE(dict.find("char"));
}

/* Test an Invalid Word Exists */
TEST(trieTest, InvalidWordFind) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  trie dict(words);

	ASSERT_FALSE(dict.find("bli"));
}

/* Test an empty Word Exists */
TEST(trieTest, EmptyWordFind) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  trie dict(words);

	ASSERT_TRUE(dict.find(""));
}

/* Test a Valid Prefix Exists */
TEST(trieTest, ValidPrefixHasPrefix) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  trie dict(words);

	ASSERT_TRUE(dict.has_prefix("cha"));
}

/* Test an Invalid Prefix Exists */
TEST(trieTest, InvalidPrefixHasPrefix) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  trie dict(words);

	ASSERT_FALSE(dict.has_prefix("bli"));
}

/* Test an empty Prefix Exists */
TEST(trieTest, EmptyPrefixHasPrefix) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  trie dict(words);

	ASSERT_TRUE(dict.has_prefix(""));
}

/* Test Inserting a word into an existing trie. */
TEST(trieTest, ExistingtrieInsert) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  trie dict(words);

	ASSERT_FALSE(dict.find("table"));

	dict.insert("table");

	ASSERT_TRUE(dict.find("table"));
}

/* Test Inserting into a Default Constructed trie. */
TEST(trieTest, InsertDefaultConstructed) {
	trie dict;

	ASSERT_FALSE(dict.find("table"));

	dict.insert("table");

	ASSERT_TRUE(dict.find("table"));
}

/* Test Copy Constructor Works */
TEST(trieTest, CopyConstructor) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
  trie dict1(words);

	ASSERT_TRUE(dict1.find("char"));

	trie dict2(dict1);

	ASSERT_TRUE(dict1.find("char"));
	ASSERT_TRUE(dict2.find("char"));
}

/* Test =operator normal usage. */
TEST(trieTest, EqualOperatorCopiesNormal) {
	std::vector<std::string> words = { "char" };
  trie dict1(words);

	ASSERT_TRUE(dict1.find("char"));

	trie dict2 = dict1;

	ASSERT_TRUE(dict1.find("char"));
	ASSERT_TRUE(dict2.find("char"));
} 

/* Test =operator edge cases. */
TEST(trieTest, EqualOperatorCopiesEdge) {
	std::vector<std::string> words = {};
  trie defaultDict;
  trie emptyDict(words);

	ASSERT_FALSE(defaultDict.find("word"));
	ASSERT_FALSE(emptyDict.find("word"));

	trie testDict1 = defaultDict;
	trie testDict2 = emptyDict;

	ASSERT_FALSE(testDict1.find("word"));
	ASSERT_FALSE(testDict2.find("word"));
} 

/* Test when Inefficient Construction is Used. */
TEST(trieTest, InefficentConstruction) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
	trie dict = trie(words);

	ASSERT_TRUE(dict.find("char"));
}

/* Test that inserting to a Copy doesn't effect the original. */
TEST(trieTest, InsertWordToCopy) {
	std::vector<std::string> words = { "char", "chai", "chair", "ant" };
	trie dictOne = trie(words);

	ASSERT_TRUE(dictOne.find("char"));

	trie dictTwo   = dictOne;
	trie dictThree(dictTwo);

	ASSERT_TRUE(dictTwo.find("char"));
	ASSERT_TRUE(dictThree.find("char"));

	dictTwo.insert("table");

	ASSERT_FALSE(dictOne.find("table"));
	ASSERT_TRUE(dictTwo.find("table"));
	ASSERT_FALSE(dictThree.find("table"));
}

/* Test that every word inserted matches its prefixes. */
TEST(trieTest, InsertedWordsHasPrefix) {
	trie dict;
	std::string test = "VeryLongStringWhichHasLotsOfPrefixes!";
	dict.insert(test);

	for (int i = 0; i < test.length(); i++) {
		std::string currPrefix = test.substr(0, i);
		ASSERT_TRUE(dict.has_prefix(currPrefix));
	}
}

TEST(trieTest, NewLineEntries) {
	trie dict = { "new\nline" };

	ASSERT_TRUE(dict.find("new\nline"));
	ASSERT_TRUE(dict.has_prefix("new\n"));
}

TEST(trieTest, NullTerminatorEntries) {
	trie dict = { "null\0terminator" };

	ASSERT_TRUE(dict.find("null\0terminator"));
	ASSERT_TRUE(dict.has_prefix("null\0"));
}

// The fixture for testing class Project1. From google test primer.
class Test_trie : public ::testing::Test {
	protected:

		Test_trie() {
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