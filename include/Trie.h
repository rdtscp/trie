#include <memory>
#include <vector>
#include <string>
#include <map>

#include "TrieNode.h"

class Trie {

  public:

    /* Constructs an Empty Trie */
    Trie();

    /* Takes in a vector of strings, and constructs a Trie. */
    Trie(std::vector<std::string> dictionary);

    /* Copy Constructor */
    Trie(const Trie& copy);

    /* Assignment Operator */
    Trie& operator=(Trie rhs);

    /* Queries the Trie to see if a string exists. */
    bool find(std::string query);

    /* Queries the Trie to see if a prefix of a string exists. */
    bool has_prefix(std::string prefix);

    /* Inserts a word into the Trie. */
    void insert(std::string word);

  private:
  
    /* Contains all the words in the dictionary starting from their first character. */
    std::map<char, std::unique_ptr<TrieNode>> dictionary;

    /* Helper for safely returning the tail of a string. */
    std::string getTail(std::string word);

};