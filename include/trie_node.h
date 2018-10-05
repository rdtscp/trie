#ifndef TRIENODE_H
#define TRIENODE_H

#include <map>
#include <string>
#include <vector>

class trie_node {

  public:

    /* Takes in a string representing the remaining portion of the word, and creates a structure accordingly. */
    trie_node(const std::string& word);

    /* Copy Constructor */
    trie_node(const trie_node& copy);

    /* Assignment Operator */
    trie_node& operator=(const trie_node& rhs);

    /* Used recursively to determine if a string exists within the parent Trie. */
    bool find(const std::string& query);

    /* Used recursively to determine if a prefix of a string exists within the parent Trie. */
    bool has_prefix(const std::string& prefix);

    /* Get all possible extensions of a prefix. If an invalid prefix is supplied, an empty vector is returned. */
    std::vector<std::string> resolve(const std::string& prefix);

    /* Used recursively to insert a word into the parent Trie. */
    void insert(const std::string& word);

  private:

    /* Marks if this trie node is an entry in the Trie. */
    bool isEntry = false;
    /* Contains all possible extensions of the word prefix up until this point. */
    std::map<char, std::unique_ptr<trie_node>> children;

    /* Helper for safely returning the tail of a string. */
    std::string getTail(const std::string& word);

};

#endif