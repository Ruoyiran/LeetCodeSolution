//
// Created by ranpeng on 2020/4/28.
//

#include "common.h"

/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/
class Solution {
public:
    bool isAnagramV1(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int size = 128;
        vector<int> hash1(size), hash2(size);
        int n = 0;
        for (int i = 0; i < s.length(); ++i) {
            ++hash1[s[i]];
            ++hash2[t[i]];
        }
        for (int i = 0; i < size; ++i) {
            if (hash1[i] != hash2[i]) {
                return false;
            }
        }
        return true;
    }

    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        int size = 26;
        vector<int> hash1(size), hash2(size);
        int n = 0;
        for (int i = 0; i < s.length(); ++i) {
            ++hash1[s[i]-'a'];
            ++hash2[t[i]-'a'];
        }
        for (int i = 0; i < size; ++i) {
            if (hash1[i] != hash2[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << Solution().isAnagram("anagram", "nagaram") << std::endl;
    std::cout << Solution().isAnagram("rat", "rat") << std::endl;
    return 0;
}