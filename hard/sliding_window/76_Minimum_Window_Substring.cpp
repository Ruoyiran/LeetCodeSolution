//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> chars(128, 0);
        for (auto c : t) {
            ++chars[c];
        }
        int left = 0, right = 0, start = 0, count = t.length();
        int minLen = INT32_MAX;
        while (right < s.length()) {
            if (chars[s[right++]]-- > 0) {
                --count;
            }
            while (0 == count) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }
                if (chars[s[left++]]++ == 0) {
                    ++count;
                }
            }
        }
        return minLen == INT32_MAX ? "" : s.substr(start, minLen);
    }
};

int main() {
    string S = "ADOBECODEBANC", T = "ABC";
    cout << Solution().minWindow(S, T) << endl;
    return 0;
}