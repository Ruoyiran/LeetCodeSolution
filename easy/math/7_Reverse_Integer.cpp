//
// Created by ranpeng on 2020/4/27.
//
#include "common.h"

/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range:
[−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
class Solution {
public:
    int reverseV1(int x) {
        if (x == INT32_MIN || x == INT32_MAX) {
            return 0;
        }
        bool isNegative = false;
        if (x < 0) {
            isNegative = true;
            x = -x;
        }
        int res = 0;
        unsigned long long tmp = 0;
        int a = 0;
        while (x > 0) {
            a = x % 10;
            tmp = res;
            res = (int) (tmp*10 + a);
            if ((res - a)/10 != tmp) {
                return 0;
            }
            x /= 10;
        }
        if (isNegative) {
            res = -res;
        }
        return res;
    }

    int reverse(int x) {
        long long res = 0;
        while (x != 0) {
            res = res * 10 + (x%10);
            x /= 10;
        }
        return (res < INT32_MIN || res > INT32_MAX) ? 0 : res;
    }
};

int main() {
    std::cout << Solution().reverse(1534236469) << std::endl;
    std::cout << Solution().reverse(-123) << std::endl;
    std::cout << Solution().reverse(1) << std::endl;
    std::cout << Solution().reverse(9) << std::endl;
    return 0;
}