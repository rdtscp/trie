#include <map>
#include <string>
#include <vector>

class TrieNode {

  public:

    TrieNode(std::string word);
    ~TrieNode();

    bool hasString(std::string query);

    bool hasPrefix(std::string prefix);

    void insert(std::string word);

  private:

    bool isEntry = false;
    std::map<char, TrieNode*> children;

    std::string getTail(std::string word);

};