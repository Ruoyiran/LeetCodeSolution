//
// Created by ranpeng on 2020/4/28.
//

#include "common.h"

/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash(26, 0);
        for (auto c : s) {
            hash[c-'a']++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (hash[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    std::cout << Solution().firstUniqChar("leetcode") << std::endl;
    std::cout << Solution().firstUniqChar("loveleetcode") << std::endl;
    return 0;
}