#include <vector>
#include <string>
#include <map>

#include "../include/trie.h"

trie_node::trie_node(const std::string& word) : children() {
  insert(word);
}

trie_node::trie_node(const trie_node& copy) {
  isEntry = copy.isEntry;
  for (const auto& subNode: copy.children) {
    children[subNode.first] = std::unique_ptr<trie_node>(new trie_node(*subNode.second));
  }
}

trie_node& trie_node::operator=(const trie_node& rhs) {
  isEntry = rhs.isEntry;
  for (const auto& subNode: rhs.children) {
    children[subNode.first] = std::unique_ptr<trie_node>(new trie_node(*subNode.second));
  }
  return *this;
}

bool trie_node::find(const std::string& word) {
  if (word == "")
    return isEntry;

  const char        head = word[0];
  const std::string tail = getTail(word);
  if (children.find(head) != children.end())
    return children[head]->find(tail);

  return false;
}

bool trie_node::has_prefix(const std::string& prefix) {
  if (prefix == "")
    return true;

  const char        head = prefix[0];
  const std::string tail = getTail(prefix);
  if (children.find(head) != children.end())
    return children[head]->has_prefix(tail);

  return false;
}

std::vector<std::string> trie_node::resolve(const std::string& prefix) {
  std::vector<std::string> output = {};

  if (prefix == "") {
    for (const auto& child: children) {
      if (child.second->isEntry)
        output.push_back(child.first+std::string());

      std::vector<std::string> extensions = child.second->resolve("");
      for (std::string& extension: extensions)
        extension = child.first + extension;
      output.insert(output.end(), extensions.begin(), extensions.end());
    }
  }
  else {
    const char        head = prefix[0];
    const std::string tail = getTail(prefix);

    if (children.find(head) != children.end()) {
      if (tail == "" && children[head]->isEntry)
        output.push_back(head + std::string());
    
      std::vector<std::string> extensions = children[head]->resolve(tail);
      for (std::string& extension: extensions)
        extension = head + extension;
      output.insert(output.end(), extensions.begin(), extensions.end());
    }
  }

  return output;
}

void trie_node::insert(const std::string& word) {
  if (word == "")
    isEntry = true;
  else {
    const char        head = word[0];
    const std::string tail = getTail(word);

    if (children.find(head) == children.end())
      children[head] = std::unique_ptr<trie_node>(new trie_node(tail));
    else
      children[head]->insert(tail);
  }
}

std::string trie_node::getTail(const std::string& word) {
  std::string output = "";
  if (word.length() > 0)
    output = word.substr(1, word.length() - 1);
  return output;
}