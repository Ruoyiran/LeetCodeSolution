//
// Created by ranpeng on 2020/4/13.
//

#include "common.h"

/*
Given a string, find the length of the longest substring without repeating characters.

返回给定字符串中的最长不重复字符串的长度
 */
class Solution {
public:
    // Time Limit Exceeded
    int lengthOfLongestSubstringV1(string s) {
        map<char, int> m;
        int longest = 0;
        int i = 0;
        for (; i < s.length(); ++i) {
            char c = s[i];
            if (m.find(c) == m.end()) {
                m[c] = i;
            } else {
                longest = std::max(longest, (int) m.size());
                i = m[c];
                m.clear();
            }
        }
        longest = std::max(longest, (int) m.size());
        return longest;
    }

    int lengthOfLongestSubstringV2(string s) {
        map<char, int> m;
        int longest = 0;
        int i = 0, start = -1;
        for (; i < s.length(); ++i) {
            char c = s[i];
            auto iter = m.find(c);
            if (iter == m.end()) {
                m[c] = i;
                if (start == -1) {
                    start = i;
                }
            } else {
                longest = std::max(longest, (int) m.size());
                int end = m[c];
                for (int j = start; j <= end; ++j) {
                    m.erase(m.find(s[j]));
                }
                m[c] = i;
                start = end+1;
            }
        }
        longest = std::max(longest, (int) m.size());
        return longest;
    }

    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int start = 0, len = 0;
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (m.find(c) != m.end()) {
                if (m[c] >= start) {
                    start = m[c] + 1;
                }
            }
            len = std::max(len, i-start+1);
            m[c] = i;
        }
        return len;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcdacdfgcg") << endl;
    cout << solution.lengthOfLongestSubstring("bbbbb") << endl;
    cout << solution.lengthOfLongestSubstring("pwwkew") << endl;
    cout << solution.lengthOfLongestSubstring(" ") << endl;
    cout << solution.lengthOfLongestSubstring("aabaab!bb") << endl;
    return 0;
}