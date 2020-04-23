//
// Created by ranpeng on 2020/4/15.
//

#include "common.h"

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or
vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool find = search(board, i, j, 0, word, visit);
                if (find) {
                    return true;
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, int i, int j, int index, const std::string& target, vector<vector<bool>> &visited) {
        if (index == target.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size()) {
            return false;
        }
        if (visited[i][j] || target[index] != board[i][j]) {
            return false;
        }
        visited[i][j] = true;
        bool find = search(board, i - 1, j, index+1, target, visited);
        find = find || search(board, i + 1, j, index+1, target, visited);
        find = find || search(board, i, j - 1, index+1, target, visited);
        find = find || search(board, i, j + 1, index+1, target, visited);
        visited[i][j] = false;
        return find;
    }
};

int main() {
    vector<vector<char>> board = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    cout << Solution().exist(board, "ABCCED") << endl;
    cout << Solution().exist(board, "SEE") << endl;
    cout << Solution().exist(board, "ABCB") << endl;
    return 0;
}