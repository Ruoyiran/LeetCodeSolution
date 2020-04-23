//
// Created by ranpeng on 2020/4/16.
//
#include "common.h"

struct TrieNode {
    bool isWord;
    unordered_map<char, TrieNode*> data;
    TrieNode() : isWord(false) {}
};

/*
Implement a trie with insert, search, and startsWith methods.

Note:

You may assume that all inputs are consist of lowercase letters a-z.
 */
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto node = root;
        for(char c : word) {
            if (node->data.find(c) == node->data.end()) {
                node->data[c] = new TrieNode();
            }
            node = node->data[c];
        }
        node->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto node = traverse(word);
        return node != NULL && node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto node = traverse(prefix);
        return node != NULL;
    }

private:
    TrieNode* traverse(const string& str) {
        auto node = root;
        for(char c : str) {
            if (node->data.find(c) == node->data.end()) {
                return NULL;
            }
            node = node->data[c];
        }
        return node;
    }
private:
    TrieNode* root;
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << boolalpha << trie.search("apple") << endl;   // returns true
    cout << boolalpha << trie.search("app") << endl;     // returns false
    cout << boolalpha << trie.startsWith("app") << endl; // returns true
    trie.insert("app");
    cout << boolalpha << trie.search("app") << endl;     // returns true
    return 0;
}