//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> substrs;
        backtracking(s, 0, substrs, res);
        return res;
    }

private:
    void backtracking(const std::string& s, int start, vector<string> &substrs, vector<vector<string>>& res) {
        if (start == s.length() && !substrs.empty()) {
            res.push_back(substrs);
            return;
        }
        for (int i = start; i < s.length(); ++i) {
            if (!isPalindrome(s, start, i)) {
                continue;
            }
            substrs.push_back(s.substr(start, i-start+1));
            backtracking(s, i+1, substrs, res);
            substrs.pop_back();
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "aab";
    auto res = Solution().partition(s);
    printMatrix<string>(res, " ");
    return 0;
}