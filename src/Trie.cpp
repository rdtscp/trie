#include <memory>
#include <vector>
#include <string>
#include <map>

#include "../include/Trie.h"

Trie::Trie() {}

Trie::Trie(std::vector<std::string> words) {
  for (std::string word: words) {
    insert(word);
  }
}

Trie::Trie(const Trie& copy) {
  for (const auto& dictEntry: copy.dictionary) {
    dictionary[dictEntry.first] = std::unique_ptr<TrieNode>(new TrieNode(*dictEntry.second));
  }
}

Trie& Trie::operator=(Trie rhs) {
  for (const auto& dictEntry: rhs.dictionary) {
    dictionary[dictEntry.first] = std::unique_ptr<TrieNode>(new TrieNode(*dictEntry.second));
  }
  return *this;
}

bool Trie::find(std::string word) {
  if (word == "")
    return true;

  char        head = word[0];
  std::string tail = getTail(word);
  if (dictionary.find(head) != dictionary.end())
    return dictionary[head]->find(tail);

  return false;
}

bool Trie::has_prefix(std::string word) {
  if (word == "")
    return true;

  char        head = word[0];
  std::string tail = getTail(word);
  if (dictionary.find(head) != dictionary.end())
    return dictionary[head]->has_prefix(tail);

  return false;
}

void Trie::insert(std::string word) {
  if (word == "")
    return;
  else {
    char        head = word[0];
    std::string tail = getTail(word);

    if (dictionary.find(head) == dictionary.end())
      dictionary[head] = std::unique_ptr<TrieNode>(new TrieNode(tail));
    else
      dictionary[head]->insert(tail);
  }
}

/* For a given string "abcd", returns the tail "bcd". Returns "" if the string is 1 character or less. */
std::string Trie::getTail(std::string word) {
  std::string output = "";
  if (word.length() > 0)
    output = word.substr(1, word.length() - 1);
  return output;
}