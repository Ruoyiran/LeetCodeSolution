//
// Created by ranpeng on 2020/4/15.
//

#include "common.h"

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?
 */
class Solution {
public:
    // Time Limit Exceeded
    int uniquePathsV1(int m, int n) {
        int count = 0;
        backtracking(m-1, n-1, 0, 0, count);
        return count;
    }

    void backtracking(int m, int n, int right, int down, int& count) {
        if (right > m || down > n) {
            return;
        }
        if (right == m && down == n) {
            ++count;
            return;
        }
        backtracking(m, n, right+1, down, count);
        backtracking(m, n, right, down+1, count);
    }

    // Dynamic Programming
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < m; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    Solution solution;
    int m = 20, n = 10;
    cout << solution.uniquePaths(m, n) << endl;
    cout << solution.uniquePathsV1(m, n) << endl;
    return 0;
}