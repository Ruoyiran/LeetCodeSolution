//
// Created by 冉鹏 on 2020/4/28.
//

#include "common.h"

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        res.reserve(m*n);
        int left = 0, right = n-1, up = 0, down = m-1;
        while (true) {
            // left -> right
            for (int i = left; i <= right; ++i) {
                res.push_back(matrix[up][i]);
            }
            if (++up > down) {
                break;
            }
            // up -> down
            for (int i = up; i <= down; ++i) {
                res.push_back(matrix[i][right]);
            }
            if (--right < left) {
                break;
            }
            // right -> left
            for (int i = right; i >= left; --i) {
                res.push_back(matrix[down][i]);
            }
            if (--down < up) {
                break;
            }
            // down -> up
            for (int i = down; i >= up; --i) {
                res.push_back(matrix[i][left]);
            }
            if (++left > right) {
                break;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {
            { 1, 2, 3, 10 },
            { 4, 5, 6, 11 },
            { 7, 8, 9, 12 }
    };
    auto res = Solution().spiralOrder(matrix);
    printVector(res);
    return 0;
}