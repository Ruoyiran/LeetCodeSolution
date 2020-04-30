//
// Created by ranpeng on 2020/4/30.
//

#include "common.h"

/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums =
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums =
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        vector<vector<int>> dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res = max(res, dfs(matrix, dp, i, j, dirs));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>> &matrix, vector<vector<int>> &dp, int i, int j, const vector<vector<int>> &dirs) {
        if (dp[i][j]) {
            return dp[i][j];
        }
        int mx = 1, m = matrix.size(), n = matrix[0].size();
        for (const auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) {
                continue;
            }
            int len = 1 + dfs(matrix, dp, x, y, dirs);
            mx = std::max(mx, len);
        }
        dp[i][j] = mx;
        return mx;
    }
};

int main() {
    vector<vector<int>> nums = {
            {9,9,4},
            {6,6,8},
            {2,1,1}
    };
    std::cout << Solution().longestIncreasingPath(nums) << std::endl;
    return 0;
}