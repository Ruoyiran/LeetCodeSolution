//
// Created by ranpeng on 2020/4/17.
//

#include "common.h"

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
 */
class Solution {
public:
    bool binarySearch(const vector<int> &row, int target) {
        int left = 0, right = row.size()-1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (row[mid] == target) {
                return true;
            }
            if (target < row[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }

    // Time Limit Exceeded
    bool searchMatrixV1(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            auto row = matrix[i];
            if (target < row[0] || target > row[n-1]) {
                continue;
            }
            bool find = binarySearch(row, target);
            if (find) {
                return true;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n-1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target) {
                return true;
            }
            if (target < matrix[i][j]) {
                --j;
            } else {
                ++i;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {
            {1,   4,  7, 11, 15},
            {2,   5,  8, 12, 19},
            {3,   6,  9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };
    cout << Solution().searchMatrix(matrix, 5) << endl;
    cout << Solution().searchMatrix(matrix, 20) << endl;
}
