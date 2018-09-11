#ifndef TRIENODE_H
#define TRIENODE_H

#include <map>
#include <string>
#include <vector>

class trie_node {

  public:

    /* Takes in a string representing the remaining portion of the word, and creates a structure accordingly. */
    trie_node(std::string word);

    /* Copy Constructor */
    trie_node(const trie_node& copy);

    /* Assignment Operator */
    trie_node& operator=(trie_node rhs);

    /* Used recursively to determine if a string exists within the parent Trie. */
    bool find(std::string query);

    /* Used recursively to determine if a prefix of a string exists within the parent Trie. */
    bool has_prefix(std::string prefix);

    /* Used recursively to insert a word into the parent Trie. */
    void insert(std::string word);

  private:

    /* Marks if this trie node is an entry in the Trie. */
    bool isEntry = false;
    /* Contains all possible extensions of the word prefix up until this point. */
    std::map<char, std::unique_ptr<trie_node>> children;

    /* Helper for safely returning the tail of a string. */
    std::string getTail(std::string word);

};

#endif