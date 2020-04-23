//
// Created by ranpeng on 2020/4/18.
//

#include "common.h"

/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"

Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


Example 2:
Input: "aaa"

Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            expandAroundCenter(s, i, i, count);
            expandAroundCenter(s, i, i+1, count);
        }
        return count;
    }

private:
    int expandAroundCenter(const std::string& s, int left, int right, int &count) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            ++count;
            --left;
            ++right;
        }
        return right - left - 1;
    }
};

int main() {
    string s = "aaa";
    cout << Solution().countSubstrings(s);
    return 0;
}