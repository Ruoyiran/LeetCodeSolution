//
// Created by ranpeng on 2020/4/18.
//

#include "common.h"

/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/
class Solution {
public:
    vector<int> findAnagramsV1(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        if (strcmp(s.c_str(), p.c_str()) == 0) {
            return {0};
        }
        unordered_map<char, int> chars;
        unordered_map<char, int> counter;
        for (auto c : p) {
            ++chars[c];
        }
        counter = chars;
        vector<int> res;
        int start = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (start == -1) {
                start = i;
            }
            if (counter.find(s[i]) == counter.end()) {
                start = -1;
                counter = chars;
                continue;
            }
            if (counter[s[i]] == 0) {
                int j = start;
                for(; j < i; ++j) {
                    if (s[j] != s[i]) {
                        ++counter[s[j]];
                        continue;
                    }
                    break;
                }
                start = j+1;
                continue;
            }
            --counter[s[i]];
            bool find = true;
            for (auto& r : counter) {
                if (r.second != 0) {
                    find = false;
                    break;
                }
            }
            if (find) {
                res.push_back(start);
                ++counter[s[start]];
                ++start;
            }
        }
        return res;
    }

    vector<int> findAnagramsV2(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        if (strcmp(s.c_str(), p.c_str()) == 0) {
            return {0};
        }
        vector<int> chars(128, 0);
        for (auto c : p) {
            ++chars[c];
        }
        vector<int> res;
        for (int i = 0; i < s.size(); ++i) {
            if (i + p.size() > s.size()) {
                break;
            }
            auto counter = chars;
            bool find = true;
            for (int j = i; j < i + p.size(); ++j) {
                if (--counter[s[j]] < 0) {
                    find = false;
                    break;
                }
            }
            if (find) {
                res.push_back(i);
            }
        }
        return res;
    }

    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        if (strcmp(s.c_str(), p.c_str()) == 0) {
            return {0};
        }
        vector<int> chars(128, 0);
        for (auto c : p) {
            ++chars[c];
        }
        vector<int> res;
        int left = 0, right = 0, count = p.length();
        while (right < s.length()) {
            if (chars[s[right++]]-- > 0) {
                --count;
            }
            if (count == 0) {
                res.push_back(left);
            }
            if (right-left == p.length() && chars[s[left++]]++ >= 0) {
                ++count;
            }
        }
        return res ;
    }
};

int main() {
    string s = "abaacbabc";
    string p = "abc";
    auto res = Solution().findAnagrams(s, p);
    printVector(res);
    return 0;
}