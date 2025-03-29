#include <iostream>
#include <string>
#include <set>
class Node {
    public:
    bool endWord;
    Node* children[26];

    Node() {
        endWord = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        
    }
};


class Trie{
    private:
    Node* root;

    public:
    Trie():root(new Node()){};

    void insertWord(std::string word) {
        Node* dummy = root;
        word = __sanitizeWord(word);
        for (auto ch: word) {
            if(dummy->children[ch-'a'] == nullptr) {
                dummy->children[ch-'a'] = new Node();
            }
            dummy = dummy->children[ch-'a'];
        }
        dummy->endWord = true;
    }

    bool searchWord(std::string word) {
        Node* dummy = root;
        word = __sanitizeWord(word);
        for (auto ch: word) {
            if(dummy->children[ch-'a'] == nullptr) {
                return false;
            }
            dummy = dummy->children[ch-'a'];
        }
        return dummy->endWord;
    }

    bool startsWith(std::string pre) {
        Node* dummy = root;
        pre = __sanitizeWord(pre);
        for (auto ch: pre) {
            if(dummy->children[ch-'a'] == nullptr) {
                return false;
            }
            dummy = dummy->children[ch-'a'];
        }
        return true;
    }

    void deleteWord(std::string word) {
        Node* dummy = root;
        word = __sanitizeWord(word);
        for (auto ch: word) {
            if(dummy->children[ch-'a'] == nullptr) {
                return;
            }
            dummy = dummy->children[ch-'a'];
        }
        if(dummy->endWord) {
            dummy->endWord = false;
        }
    }

    void displayTrie() {
        __displayTrieHelper("", root);
    }

    private:
    std::set<char> validChar = {'-', '_', '\'', '\"'};
    void __displayTrieHelper(std::string pre, Node* node) {
        if(node->endWord) {
            std::cout<<pre<<'\n';
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                __displayTrieHelper(pre+char(i+'a'), node->children[i]);
            }
        }
    }

    std::string __sanitizeWord(std::string word) {
        std::string res = "";
        for (auto i : word) {
            if(isalpha(i)) {
                res += (islower(i)?i:tolower(i));
            } else if (validChar.find(i) != validChar.end()) {
                res += i;
            }
        }
        return res;
    }
};