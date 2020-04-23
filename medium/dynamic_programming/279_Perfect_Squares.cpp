//
// Created by ranpeng on 2020/4/17.
//

#include "common.h"

/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/
class Solution {
public:
    // DP
    int numSquaresV1(int n) {
        if (n < 1) {
            return 0;
        }
        vector<int> dp(n+1, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j*j <= i; ++j) {
                dp[i] = std::min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }

    // BFS
    int numSquares(int n) {
        vector<int> prefectSquares;
        queue<int> q;
        vector<bool> visited(n+1, false);
        for (int i = 1; i*i <= n; ++i) {
            int t = i*i;
            if (t == n) {
                return 1;
            }
            prefectSquares.push_back(t);
            q.push(t);
            visited[t] = true;
        }
        int count = 1;
        while (!q.empty()) {
            ++count;
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                int num = q.front(); q.pop();
                for (int s : prefectSquares) {
                    int sum = num + s;
                    if (sum == n) {
                        return count;
                    }
                    if (sum > n) {
                        break;
                    }
                    if (!visited[sum]) {
                        visited[sum] = true;
                        q.push(sum);
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    cout << Solution().numSquares(43) << endl;
    return 0;
}