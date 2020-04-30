//
// Created by ranpeng on 2020/4/30.
//

#include "common.h"

/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]
Example 2:

Input:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
[]
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> cache;
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        return dfs(s, words, cache);
    }

    vector<string> dfs(string s, unordered_set<string> &words, unordered_map<string, vector<string>> &cache) {
        if (cache.count(s) > 0) {
            return cache[s];
        }
        vector<string> res;
        for (int i = 0; i < s.length()-1; ++i) {
            auto b = s.substr(i+1);
            if (words.count(b) == 0) {
                continue;
            }
            auto tmp = dfs(s.substr(0, i+1), words, cache);
            for(auto& a : tmp) {
                res.push_back(a + " " + b);
            }
        }
        if (words.count(s) > 0) {
            res.push_back(s);
        }
        cache[s] = res;
        return res;
    }
};

int main() {
    string s = "pineapplepenapple";
    vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    auto res = Solution().wordBreak(s, wordDict);
    printVector(res, "\n");
    return 0;
}