#include <map>
#include <string>
#include <vector>

#include "TrieNode.h"

class Trie {

  public:

    Trie(std::vector<std::string> dictionary);

    bool hasString(std::string query);

    bool hasPrefix(std::string prefix);

  private:

    std::map<char, TrieNode*> dictionary;

    std::string getTail(std::string word);

};