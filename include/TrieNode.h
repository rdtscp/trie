#include <map>
#include <string>
#include <vector>

class TrieNode {

  public:

    /* Takes in a string representing the remaining portion of the word, and creates a structure accordingly. */
    TrieNode(std::string word);

    /* Copy Constructor */
    TrieNode(const TrieNode& copy);

    /* Assignment Operator */
    TrieNode& operator=(TrieNode rhs);

    /* Used recursively to determine if a string exists within the parent Trie. */
    bool hasString(std::string query);

    /* Used recursively to determine if a prefix of a string exists within the parent Trie. */
    bool hasPrefix(std::string prefix);

    /* Used recursively to insert a word into the parent Trie. */
    void insert(std::string word);

  private:

    /* Marks if this trie node is an entry in the Trie. */
    bool isEntry = false;
    /* Contains all possible extensions of the word prefix up until this point. */
    std::map<char, std::unique_ptr<TrieNode>> children;

    /* Helper for safely returning the tail of a string. */
    std::string getTail(std::string word);

};