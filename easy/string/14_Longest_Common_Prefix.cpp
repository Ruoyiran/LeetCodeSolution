//
// Created by ranpeng on 2020/4/27.
//

#include "common.h"

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = INT32_MAX;
        for (auto& s : strs) {
            minLen = std::min(minLen, (int)s.length());
        }
        if (minLen <= 0) {
            return "";
        }
        for (int i = 0; i < minLen; ++i) {
            bool isEqual = true;
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (c != strs[j][i]) {
                    isEqual = false;
                    break;
                }
            }
            if (!isEqual) {
                return strs[0].substr(0, i);
            }
        }
        return strs[0].substr(0, minLen);
    }
};

int main() {
    vector<string> strs = {
            "flower","flow","flight"
    };
    std::cout << Solution().longestCommonPrefix(strs) << std::endl;
    return 0;
}