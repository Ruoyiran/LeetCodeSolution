//
// Created by ranpeng on 2020/4/30.
//

#ifndef LEETCODE_TRIE_H
#define LEETCODE_TRIE_H

#include "common.h"

struct TrieNode {
    bool isWord;
    unordered_map<char, TrieNode*> child;
    TrieNode() : isWord(false) {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }

    void insert(const std::vector<string>& words) {
        for (const auto& word : words) {
            insert(word);
        }
    }

    /** Inserts a word into the trie. */
    void insert(const string& word) {
        auto node = root;
        for(char c : word) {
            if (node->child.find(c) == node->child.end()) {
                node->child[c] = new TrieNode();
            }
            node = node->child[c];
        }
        node->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string& word) {
        auto node = traverse(word);
        return node != NULL && node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto node = traverse(prefix);
        return node != NULL;
    }

public:
    TrieNode* getRoot() {
        return root;
    }

private:
    TrieNode* traverse(const string& str) {
        auto node = root;
        for(char c : str) {
            if (node->child.find(c) == node->child.end()) {
                return NULL;
            }
            node = node->child[c];
        }
        return node;
    }
private:
    TrieNode* root;
};

#endif //LEETCODE_TRIE_H
