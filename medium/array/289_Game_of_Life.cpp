//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by
the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight
neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is
created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input:
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output:
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells
first and then use their updated values to update other cells.

In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems
when the active area encroaches the border of the array. How would you address these problems?
*/

class Solution {
public:
    enum State {
        DEAD = 0,
        LIVE = 1,
        L2D = 2,
        D2L = 3
    };

    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        int rows = board.size();
        int cols = board[0].size();
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                board[r][c] = (int) getNextState(board, r, c, rows, cols);
            }
        }

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (board[r][c] == L2D) {
                    board[r][c] = DEAD;
                } else if (board[r][c] == D2L) {
                    board[r][c] = LIVE;
                }
            }
        }
    }

private:
    State getNextState(vector<vector<int>>& board, int r, int c, int rows, int cols) {
        /*
         1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
         2. Any live cell with two or three live neighbors lives on to the next generation.
         3. Any live cell with more than three live neighbors dies, as if by over-population..
         4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
         */
        int liveCount = 0;
        for (int i = r-1; i <= r+1; ++i) {
            for (int j = c-1; j <= c+1; ++j) {
                if ((i == r && j == c) || i < 0 || i >= rows || j < 0 || j >= cols) {
                    continue;
                }
                if (board[i][j] == LIVE || board[i][j] == L2D) {
                    ++liveCount;
                }
            }
        }
        if (board[r][c] == LIVE) { // current live
            if (liveCount < 2 || liveCount > 3) { // live to dead
                return L2D;
            } else { // keep live
                return LIVE;
            }
        } else { // current dead
            if (liveCount == 3) { // dead to live
                return D2L;
            } else { // keep dead
                return DEAD;
            }
        }
    }
};

int main() {
    vector<vector<int>> board = {
            {0,1,0},
            {0,0,1},
            {1,1,1},
            {0,0,0}
    };
    printMatrix(board);
    std::cout << "After: \n";
    Solution().gameOfLife(board);
    printMatrix(board);
    return 0;
}