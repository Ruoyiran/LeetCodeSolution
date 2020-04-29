//
// Created by ranpeng on 2020/4/29.
//
#include "common.h"

/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to
'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visits(rows, vector<bool>(cols, false));
        // 把边界的'O'的连通域修改为'$'
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (!visits[r][c] && board[r][c] == 'O' && (r == 0 || r == rows-1 || c == 0 || c == cols-1)) {
                    traverse(board, r, c, rows, cols, visits, '$');
                }
            }
        }
        // 剩下的'O'则被'X'包围
        for (int r = 1; r < rows-1; ++r) {
            for (int c = 1; c < cols-1; ++c) {
                if (!visits[r][c] && board[r][c] == 'O') {
                    traverse(board, r, c, rows, cols, visits, 'X');
                }
            }
        }
        // 还原所有被修改为'$'的字符为'O'
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == '$') {
                    board[r][c] = 'O';
                }
            }
        }
    }

private:
    void traverse(vector<vector<char>>& board, int r, int c, int rows, int cols, vector<vector<bool>> &visits, char newSign) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return;
        }
        if (visits[r][c] || board[r][c] != 'O') {
            return;
        }
        visits[r][c] = true;
        board[r][c] = newSign;
        traverse(board, r-1, c, rows, cols, visits, newSign); // left
        traverse(board, r+1, c, rows, cols, visits, newSign); // right
        traverse(board, r, c-1, rows, cols, visits, newSign); // up
        traverse(board, r, c+1, rows, cols, visits, newSign); // down
    }
};

int main() {
    vector<vector<char>> board = {
            { 'X', 'X', 'X', 'X'},
            { 'X', 'O', 'O', 'X'},
            { 'X', 'X', 'O', 'X'},
            { 'X', 'O', 'X', 'X'},
    };
    Solution().solve(board);
    printMatrix(board, " ");
    return 0;
}