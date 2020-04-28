//
// Created by ranpeng on 2020/4/27.
//

#include "common.h"

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false
*/

class Solution {
public:
    bool isPalindromeV1(string s) {
        int left = 0, right = s.length()-1;
        while (left <= right) {
            while (left < s.length() && !std::isalnum(s[left])) {
                ++left;
            }
            while (right >= 0 && !std::isalnum(s[right])) {
                --right;
            }
            if (left < s.length() && right >= 0 && std::tolower(s[left++]) != std::tolower(s[right--])) {
                return false;
            }
        }
        return true;
    }

    bool isPalindrome(string s) {
        int left = 0, right = s.length()-1;
        while (left <= right) {
            if (!std::isalnum(s[left])) {
                ++left;
            } else if (!std::isalnum(s[right])) {
                --right;
            } else if (std::tolower(s[left++]) != std::tolower(s[right--])) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << std::endl;
    std::cout << Solution().isPalindrome("race a car") << std::endl;
    std::cout << Solution().isPalindrome("   ") << std::endl;
}