//
// Created by ranpeng on 2020/4/30.
//

#include "common.h"

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like ? or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input:
s = "cb"
p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input:
s = "adceb"
p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input:
s = "acdcb"
p = "a*c?b"
Output: false
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int sLen = s.length(), pLen = p.length();
        int i = 0, j = 0, sStar = -1, pStar = -1;
        while (i < sLen) {
            if (i < sLen && j < pLen && (s[i] == p[j] || p[j] == '?')) { // single match
                ++i;
                ++j;
            } else if (j < pLen && p[j] == '*') {
                sStar = i;
                pStar = j++;
            } else {
                if (pStar >= 0) {
                    i = ++sStar; // move forward for matching
                    j = pStar+1; // keep pattern pointer to the next of '*'
                } else {
                    return false;
                }
            }
        }
        while (j < pLen && p[j] == '*') {
            ++j;
        }
        return j == pLen;
    }
};

int main() {
    std::cout << boolalpha << Solution().isMatch("aa", "a") << std::endl;
    std::cout << boolalpha << Solution().isMatch("aa", "*") << std::endl;
    std::cout << boolalpha << Solution().isMatch("cb", "?a") << std::endl;
    std::cout << boolalpha << Solution().isMatch("adceb", "a*b") << std::endl;
    std::cout << boolalpha << Solution().isMatch("adceb", "a*b***") << std::endl;
    std::cout << boolalpha << Solution().isMatch("abefcdgiescdfimde", "ab*cd?i*de") << std::endl;
    return 0;
}