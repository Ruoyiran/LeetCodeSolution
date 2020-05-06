//
// Created by ranpeng on 2020/5/6.
//

#include "common.h"

/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two
characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, char> hash1, hash2;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (hash1.find(c) != hash1.end() && hash1[c] != t[i]) {
                return false;
            }
            if (hash2.find(t[i]) != hash2.end() && hash2[t[i]] != c) {
                return false;
            }
            hash1[c] = t[i];
            hash2[t[i]] = c;
        }
        return true;
    }
};

int main() {
    std::cout << Solution().isIsomorphic("egg", "add") << std::endl;
    std::cout << Solution().isIsomorphic("foo", "bar") << std::endl;
    std::cout << Solution().isIsomorphic("bar", "foo") << std::endl;
    std::cout << Solution().isIsomorphic("paper", "title") << std::endl;
    std::cout << Solution().isIsomorphic("ab", "aa") << std::endl;
    return 0;
}