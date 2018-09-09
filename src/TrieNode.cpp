#include <vector>
#include <string>
#include <map>

#include "../include/Trie.h"

TrieNode::TrieNode(std::string word) {
  insert(word);
}

bool TrieNode::hasString(std::string word) {
  /* @TODO */
  return true;
}

void TrieNode::insert(std::string word) {
  /* @TODO */
}

std::string TrieNode::getTail(std::string word) {
  std::string output = "";
  if (word.length() > 0)
    output = word.substr(1, word.length() - 1);
  return output;
}