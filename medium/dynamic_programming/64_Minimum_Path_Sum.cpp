//
// Created by ranpeng on 2020/4/15.
//

#include "common.h"

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes
the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */
class Solution {
public:
    // Time Limit Exceeded
    int minPathSumV1(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int minSum = INT32_MAX;
        backtracking(grid, m, n, 0, 0, 0, minSum);
        return minSum;
    }

    void backtracking(const vector<vector<int>>& grid, int m, int n, int right, int down, int sum, int &minSum) {
        if (right >= m || down >= n) {
            return;
        }
        sum += grid[down][right];
        if (right == m-1 && down == n-1) {
            minSum = std::min(minSum, sum);
            return;
        }
        backtracking(grid, m, n, right+1, down, sum, minSum);
        backtracking(grid, m, n, right, down+1, sum, minSum);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for (int j = 1; j < m; ++j) {
            dp[0][j] = grid[0][j] + dp[0][j-1];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                dp[i][j] = grid[i][j] + std::min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};

int main() {
    vector<vector<int>> nums = {
            {{5,0,1,1,2,1,0,1,3,6,3,0,7,3,3,3,1},{1,4,1,8,5,5,5,6,8,7,0,4,3,9,9,6,0},{2,8,3,3,1,6,1,4,9,0,9,2,3,3,3,8,4},{3,5,1,9,3,0,8,3,4,3,4,6,9,6,8,9,9},{3,0,7,4,6,6,4,6,8,8,9,3,8,3,9,3,4},{8,8,6,8,3,3,1,7,9,3,3,9,2,4,3,5,1},{7,1,0,4,7,8,4,6,4,2,1,3,7,8,3,5,4},{3,0,9,6,7,8,9,2,0,4,6,3,9,7,2,0,7},{8,0,8,2,6,4,4,0,9,3,8,4,0,4,7,0,4},{3,7,4,5,9,4,9,7,9,8,7,4,0,4,2,0,4},{5,9,0,1,9,1,5,9,5,5,3,4,6,9,8,5,6},{5,7,2,4,4,4,2,1,8,4,8,0,5,4,7,4,7},{9,5,8,6,4,4,3,9,8,1,1,8,7,7,3,6,9},{7,2,3,1,6,3,6,6,6,3,2,3,9,9,4,4,8}}
    };
    cout << Solution().minPathSum(nums) << endl;
    cout << Solution().minPathSumV1(nums) << endl;
    return 0;
}