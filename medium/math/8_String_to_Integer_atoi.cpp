//
// Created by 冉鹏 on 2020/4/28.
//

#include "common.h"

/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as
possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no
effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists
because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range:
[−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
*/
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }
        int start = 0, end = str.length()-1;
        while (start < str.length() && str[start] == ' ') {
            ++start;
        }
        while (end >= 0 && str[end] == ' ') {
            --end;
        }
        if (start > end) {
            return 0;
        }

        bool isNegative = false;
        if (str[start] == '-') {
            ++start;
            isNegative = true;
        } else if (str[start] == '+') {
            ++start;
        }
        if (start > end) {
            return 0;
        }

        int res = 0, n;
        long long t = 0;
        for (int i = start; i <= end; ++i) {
            if (str[i] < '0' || str[i] > '9') {
                break;
            }
            n = str[i] - '0';
            t = t * 10 + n;
            if (t > INT32_MAX) {
                return isNegative ? INT32_MIN : INT32_MAX;
            }
            res = (int) t;
        }
        return isNegative ? -res : res;
    }
};

int main() {
    std::cout << Solution().myAtoi("42") << std::endl;
    std::cout << Solution().myAtoi("-42") << std::endl;
    std::cout << Solution().myAtoi("2147483648") << std::endl;
    std::cout << Solution().myAtoi("21474836411") << std::endl;
    std::cout << Solution().myAtoi("-21474836411") << std::endl;
    std::cout << Solution().myAtoi("+12") << std::endl;
    std::cout << Solution().myAtoi("-12") << std::endl;
    return 0;
}
