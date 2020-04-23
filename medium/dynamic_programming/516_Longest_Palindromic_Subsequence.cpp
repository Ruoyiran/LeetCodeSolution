//
// Created by ranpeng on 2020/4/23.
//
#include "common.h"

/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:
    "bbbab"
Output:
    4
One possible longest palindromic subsequence is "bbbb".

Example 2:
Input:
    "cbbd"
Output:
    2
One possible longest palindromic subsequence is "bb"
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        /*
        dp[i][j]:表示对于s[i to j]这一子串中的最长回文子序列长度。
        当i = j dp[i][j] = 1;
        当i > j dp[i][j] = 0;
        当i < j && s[i] = s[j] dp[i][j] = dp[i+1][j-1]+2;
        当i < j && s[i] != s[j] dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
         */
        vector<vector<int>>dp(n,vector<int>(n));
        for(int i = n-1; i >= 0; --i) {
            dp[i][i] = 1;
            for(int j = i+1; j < n; ++j) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1]+2;
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};

int main() {
    cout << Solution().longestPalindromeSubseq("bbbab") << endl;
}