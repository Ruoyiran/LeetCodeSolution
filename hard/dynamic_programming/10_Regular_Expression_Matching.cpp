//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
class Solution {
public:
    bool isMatchV1(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        bool firstMatch = (!s.empty()) && (s[0] == p[0] || p[0] == '.');
        // *表示可以代替任意个数的字符，a*b，可以表示b或是 aaab，即a的个数任意
        // 只有长度大于 2 的时候，才考虑 *
        if (p.length() >= 2 && p[1] == '*') {
            // 两种情况
            // 1. pattern直接跳过两个字符。表示 * 前边的字符出现 0 次
            // 2. pattern不变，例如text = aa，pattern = a*，第一个a匹配，
            // 然后text的第二个a接着和pattern的第一个a进行匹配。表示*用前一个字符替代。
            return (isMatch(s, p.substr(2))) ||
                   (firstMatch && isMatch(s.substr(1), p));
        }else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }

    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int j = 1; j < n && p[j] == '*'; j+=2) {
            dp[0][j + 1] = true;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (p[j] != '*') {
                    dp[i+1][j+1] = p[j] == '.' ? dp[i][j] : (dp[i][j] && s[i] == p[j]);
                } else {
                    if (j > 0) {
                        dp[i+1][j+1] = dp[i+1][j-1] ||  // a* indicates empty a
                                       dp[i+1][j] || // a* single a
                                       (dp[i][j+1] && (p[j-1]==s[i] || p[j-1] == '.')); // a* indicates multiply a

                    }
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    string s = "aa";
    string p = ".*";
    cout << Solution().isMatch(s, p) << endl;
    return 0;
}
