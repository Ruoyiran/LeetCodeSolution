//
// Created by ranpeng on 2020/4/23.
//

#include "common.h"

/*
Given two strings text1 and text2, return the length of their longest common subsequence.

A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted
without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde" while "aec" is
not). A common subsequence of two strings is a subsequence that is common to both strings.

If there is no common subsequence, return 0.

Example 1:

Input: text1 = "abcde", text2 = "ace"
Output: 3
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 */
class Solution {
public:
    /*
     这是一道很典型的动态规划题目。对于这种关于计算两个字符串之间的关系的题，大多都是定义一个二维数组， 数组中的每个元素都表示一个状态。
     对于这一题，我们可以定义一个二维数组dp[i][j]dp[i][j]dp[i][j]，数组中的每一个元素表示当前状态（即text1的前i个字符和text2的前
     j个字符可以计算得出的最长子字符串，需要注意的是这里的ji和j并不包括在内。）下最长相同子字符串的长度， 那么下一步就应该分析状态转移
     方程。

     很明显，当我们扫描到text1的第i个字符，text2的第j个字符时，需要考虑这两个字符是否相等，如果这两个字符相等，很明显，计算出的结果应
     该是text1的前i−1和text2的前j−1个计算出的最长子字符串的长度加1，即：
     dp[i][j]=dp[i−1][j−1]+1

     当两个字符不相等时，我们就需要考虑dp[i−1][j]以及dp[i][j−1]，因为当前的两个字符已经不相等了，所以我们没有办法在原有的基础上更进
     一步，只能在dp[i−1][j]以及dp[i][j−1]中选择一个最大值，即：
     dp[i][j]=max(dp[i−1][j],dp[i][j−1])
     */
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(), n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i-1] == text2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    cout << Solution().longestCommonSubsequence("abcde", "ace") << endl;
    cout << Solution().longestCommonSubsequence("abc", "abc") << endl;
    cout << Solution().longestCommonSubsequence("abc", "def") << endl;
    return 0;
}