#include <vector>
#include <string>
#include <map>

#include "../include/Trie.h"

TrieNode::TrieNode(std::string word) : children() {
  insert(word);
}

TrieNode::TrieNode(const TrieNode& copy) {
  isEntry = copy.isEntry;
  for (const auto& subNode: copy.children) {
    children[subNode.first] = std::unique_ptr<TrieNode>(new TrieNode(*subNode.second));
  }
}

TrieNode& TrieNode::operator=(TrieNode rhs) {
  isEntry = rhs.isEntry;
  for (const auto& subNode: rhs.children) {
    children[subNode.first] = std::unique_ptr<TrieNode>(new TrieNode(*subNode.second));
  }
  return *this;
}

bool TrieNode::find(std::string word) {
  if (word == "")
    return isEntry;

  char        head = word[0];
  std::string tail = getTail(word);
  if (children.find(head) != children.end())
    return children[head]->find(tail);

  return false;
}

bool TrieNode::has_prefix(std::string prefix) {
  if (prefix == "")
    return true;

  char        head = prefix[0];
  std::string tail = getTail(prefix);
  if (children.find(head) != children.end())
    return children[head]->has_prefix(tail);

  return false;
}

void TrieNode::insert(std::string word) {
  if (word == "")
    isEntry = true;
  else {
    char        head = word[0];
    std::string tail = getTail(word);

    if (children.find(head) == children.end())
      children[head] = std::unique_ptr<TrieNode>(new TrieNode(tail));
    else
      children[head]->insert(tail);
  }
}

std::string TrieNode::getTail(std::string word) {
  std::string output = "";
  if (word.length() > 0)
    output = word.substr(1, word.length() - 1);
  return output;
}