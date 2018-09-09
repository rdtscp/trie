#include <vector>
#include <string>
#include <map>

#include "../include/Trie.h"

Trie::Trie(std::vector<std::string> words) {
  for (std::string word: words) {
    char        head = word[0];
    std::string tail = getTail(word);

    if (dictionary.find(head) == dictionary.end()) {
      dictionary[head] = new TrieNode(tail);
    }
    else {
      dictionary[head]->insert(tail);
    }
  }
}

bool Trie::hasString(std::string word) {
  if (word == "")
    return true;

  char        head = word[0];
  std::string tail = getTail(word);
  if (dictionary.find(head) != dictionary.end())
    return dictionary[head]->hasString(tail);

  return false;
}

bool Trie::hasPrefix(std::string word) {
  if (word == "")
    return true;

  char        head = word[0];
  std::string tail = getTail(word);
  if (dictionary.find(head) != dictionary.end())
    return dictionary[head]->hasPrefix(tail);

  return false;
}

/* For a given string "abcd", returns the tail "bcd". Returns "" if the string is 1 character or less. */
std::string Trie::getTail(std::string word) {
  std::string output = "";
  if (word.length() > 0)
    output = word.substr(1, word.length() - 1);
  return output;
}