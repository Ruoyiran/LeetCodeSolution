//
// Created by ranpeng on 2020/4/30.
//

#include "common.h"
#include "trie.h"

/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example:

Input:
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/
class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, string& s, vector<string>& res){
        char c = board[x][y];
        if (c == '#' || root->child.count(c) == 0) {
            return;
        }
        s.push_back(c);
        root = root->child[c];
        if (root->isWord) {
            res.push_back(s);
            root->isWord = false;
        }
        board[x][y] = '#';
        if(x > 0) {
            dfs(board, x-1, y, root, s, res);
        }
        if(y > 0) {
            dfs(board, x, y-1, root, s, res);
        }
        if(x+1 < board.size()) {
            dfs(board,x+1, y, root, s, res);
        }
        if(y+1 < board[0].size()) {
            dfs(board, x, y+1, root, s, res);
        }
        board[x][y] = c;
        s.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie = new Trie();
        trie->insert(words);
        auto root = trie->getRoot();
        int m = board.size();
        int n = board[0].size();
        vector<string> res;
        string s;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, root, s, res);
            }
        }
        delete trie;
        return res;
    }
};

int main() {
    vector<vector<char>> board = {
            {'o','a','a','n'},
            {'e','t','a','e'},
            {'i','h','k','r'},
            {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    auto res = Solution().findWords(board, words);
    printVector(res, " ");
    board = {
            {'a', 'a'}
    };
    words = {"aaa"};
    res = Solution().findWords(board, words);
    printVector(res, " ");

    board = {{'a', 'b'}, {'a', 'a'}};
    words = {"aba","baa","bab","aaab","aaa","aaaa","aaba"};
    res = Solution().findWords(board, words);
    printVector(res, " ");
    return 0;
}
