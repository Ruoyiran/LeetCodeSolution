//
// Created by 冉鹏 on 2020/4/28.
//

#include "common.h"

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() | matrix[0].empty()) {
            return;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> firstRow(cols, 1);
        vector<int> firstCol(rows, 1);
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == 0) {
                    firstRow[c] = 0;
                    firstCol[r] = 0;
                }
            }
        }

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (firstCol[r] == 0 || firstRow[c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
            {0,1,2,0},
            {3,4,5,2},
            {1,3,1,5}
    };
    Solution().setZeroes(matrix);
    for (auto& r : matrix) {
        printVector(r);
    }
    return 0;
}