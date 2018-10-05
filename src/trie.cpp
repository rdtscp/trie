#include <memory>
#include <vector>
#include <string>
#include <map>

#include "../include/trie.h"

using namespace ads;

trie::trie() {}

trie::trie(const std::vector<std::string>& dictionary) {
  for (std::string word: dictionary) {
    insert(word);
  }
}

trie::trie(const std::initializer_list<std::string>& dictionary) {
  for (std::string word: dictionary) {
    insert(word);
  }
}

trie::trie(const trie& copy) {
  for (const auto& dictEntry: copy.dictionary) {
    dictionary[dictEntry.first] = std::unique_ptr<trie_node>(new trie_node(*dictEntry.second));
  }
}

trie& trie::operator=(const trie& rhs) {
  if (&rhs == this) {
    return *this;
  }
  for (const auto& dictEntry: rhs.dictionary) {
    dictionary[dictEntry.first] = std::unique_ptr<trie_node>(new trie_node(*dictEntry.second));
  }
  return *this;
}

bool trie::find(const std::string& word) {
  if (word == "")
    return true;

  char        head = word[0];
  std::string tail = getTail(word);
  if (dictionary.find(head) != dictionary.end())
    return dictionary[head]->find(tail);

  return false;
}

bool trie::has_prefix(const std::string& word) {
  if (word == "")
    return true;

  char        head = word[0];
  std::string tail = getTail(word);
  if (dictionary.find(head) != dictionary.end())
    return dictionary[head]->has_prefix(tail);

  return false;
}

void trie::insert(const std::string& word) {
  if (word == "")
    return;
  else {
    char        head = word[0];
    std::string tail = getTail(word);

    if (dictionary.find(head) == dictionary.end())
      dictionary[head] = std::unique_ptr<trie_node>(new trie_node(tail));
    else
      dictionary[head]->insert(tail);
  }
}

/* For a given string "abcd", returns the tail "bcd". Returns "" if the string is 1 character or less. */
std::string trie::getTail(const std::string& word) {
  std::string output = "";
  if (word.length() > 0)
    output = word.substr(1, word.length() - 1);
  return output;
}