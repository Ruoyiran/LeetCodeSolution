//
// Created by 冉鹏 on 2020/4/28.
//

#include "common.h"

/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            auto& row = board[i];
            if (!isValid(row)) {
                return false;
            }
        }
        for (int j = 0; j < 9; ++j) {
            vector<char> tmp(9);
            for (int i = 0; i < 9; ++i) {
                tmp[i] = board[i][j];
            }
            if (!isValid(tmp)) {
                return false;
            }
        }
        for (int i = 0; i < 9; i+=3) {
            for (int j = 0; j < 9; j+=3) {
                auto tmp = getBlock3x3(board, i, j);
                if (!isValid(tmp)) {
                    return false;
                }
            }
        }
        return true;
    }

private:
    vector<char> getBlock3x3(const vector<vector<char>>& board, int i, int j) {
        vector<char> chars;
        chars.reserve(9);
        for (int m = i; m < i+3; ++m) {
            for (int n = j; n < j+3; ++n) {
                chars.push_back(board[m][n]);
            }
        }
        return chars;
    }

    bool isValid(const vector<char>& chars) {
        unordered_set<char> s;
        for (int i = 0; i < 9; ++i) {
            if (s.find(chars[i]) != s.end()) {
                return false;
            }
            if (chars[i] >= '0' && chars[i] <= '9') {
                s.insert(chars[i]);
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'}
    };
    std::cout << Solution().isValidSudoku(board) << std::endl;
    return 0;
}