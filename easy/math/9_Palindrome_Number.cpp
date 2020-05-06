//
// Created by ranpeng on 2020/5/6.
//

#include "common.h"

/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/

/*
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long a = x;
        long long b = 0;
        while (x > 0) {
            b = b*10 + x % 10;
            x /= 10;
        }
        return a == b;
    }
};

int main() {
    std::cout << Solution().isPalindrome(12321) << std::endl;
    std::cout << Solution().isPalindrome(129454921) << std::endl;
    std::cout << Solution().isPalindrome(10) << std::endl;
    return 0;
}