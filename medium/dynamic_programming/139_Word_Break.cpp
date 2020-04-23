//
// Created by ranpeng on 2020/4/16.
//

#include "common.h"

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false
 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> set;
        for (auto &str : wordDict) {
            set.insert(str);
        }
        vector<bool> dp(s.size());
        dp[0] = set.find(s.substr(0, 1)) != set.end();
        for (int i = 1; i < s.length(); ++i) {
            if (set.find(s.substr(0, i + 1)) != set.end()) {
                dp[i] = true;
            } else {
                dp[i] = false;
                for (int j = 0; j < i; ++j) {
                    if (dp[j] && set.find(s.substr(j + 1, i - j)) != set.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size() - 1];
    }
};

int main() {
    string s = "aaaaaaa";
    vector<string> wordDict = {"aaaa", "aaa"};
    cout << Solution().wordBreak(s, wordDict) << endl;
    return 0;
}