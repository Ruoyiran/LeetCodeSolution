//
// Created by ranpeng on 2020/5/6.
//

#include "common.h"

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }
        int start = 0, end = s.length()-1;
        while (end >= 0 && s[end] == ' ') {
            --end;
        }
        start = end;
        while (start >= 0 && s[start] != ' ') {
            --start;
        }
        return end-start;
    }
};

int main() {
    std::cout << Solution().lengthOfLastWord("Hello world") << std::endl;
    return 0;
}