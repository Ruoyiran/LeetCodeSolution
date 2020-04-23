//
// Created by ranpeng on 2020/4/19.
//
#include "common.h"

/*
Given a string containing just the characters ‘(‘ and ‘)‘, find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 */
class Solution {
public:
    int longestValidParenthesesV1(string s) {
        stack<int> lefts;
        int maxLen = 0, last = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                lefts.push(i);
            }
            else {
                if (lefts.empty()) {
                    last = i;
                } else {
                    lefts.pop();
                    if (lefts.empty()) {
                        maxLen = std::max(maxLen, i-last);
                    }else {
                        maxLen = std::max(maxLen, i-lefts.top());
                    }
                }
            }
        }
        return maxLen;
    }

    int longestValidParentheses(string s) {
        if(s.empty()) {return 0;}
        vector<int> dp(s.length(), 0);
        int max = 0;
        for(int i = 1; i < s.length(); ++i) {
            if(')' == s[i]) {
                if('(' == s[i - 1]) {
                    dp[i] = (i >= 2 ? dp[i - 2]: 0) + 2;
                } else if(i - dp[i - 1] >= 1 && '(' == s[i - dp[i - 1] - 1]) {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2? dp[i - dp[i - 1] - 2]: 0) + 2;
                }
            }
            max = std::max(max, dp[i]);
        }
        return max;
    }

};


int main() {
    string s = "(()";
    cout << Solution().longestValidParentheses(s) << endl;
}