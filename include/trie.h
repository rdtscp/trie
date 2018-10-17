#ifndef TRIE_H
#define TRIE_H

#include <memory>
#include <vector>
#include <string>
#include <map>

#include "trie_node.h"


namespace ads {
  
  class trie {

    public:

      /* Constructs an Empty Trie */
      trie();

      /* Takes in a vector of strings, and constructs a Trie. */
      trie(const std::vector<std::string>& dictionary);

      /* Initialiser-List Constructor */
      trie(const std::initializer_list<std::string>& dictionary);

      /* Copy Constructor */
      trie(const trie& copy);

      /* Assignment Operator */
      trie& operator=(const trie& rhs);

      /* Queries the Trie to see if a string exists. */
      bool find(const std::string& query) const;

      /* Queries the Trie to see if a prefix of a string exists. */
      bool has_prefix(const std::string& prefix) const;

      /* Get all possible extensions of a prefix. If an invalid prefix is supplied, an empty vector is returned. */
      std::vector<std::string> resolve(const std::string& prefix) const;

      /* Inserts a word into the Trie. */
      void insert(const std::string& word);

    private:
    
      /* Contains all the words in the dictionary starting from their first character. */
      std::map<char, std::unique_ptr<trie_node>> dictionary;

      /* Helper for safely returning the tail of a string. */
      std::string getTail(const std::string& word) const;

  };

} // ads

#endif