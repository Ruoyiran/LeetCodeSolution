//
// Created by 冉鹏 on 2020/4/28.
//

#include "common.h"

/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return dividend > 0 ? INT32_MAX : INT32_MIN;
        }
        if (dividend == 0) {
            return 0;
        }
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long m = labs(dividend);
        long long n = labs(divisor);
        long long res = 0;
        /*
         将整数转化成二进制形式，即num = a0*2^0 + a1*2^1 + a2*2^2 + ... + an*2^n。基于以上这个公式以及左移一位相当于乘以2，可以先让除数左
         移直到大于被除数之前得到一个最大的基数。然后每次用被除数去减去这个基数，同时结果增加2^k。接下来继续重新左移除数左移迭代，直到被除数不大于
         除数为止。因为这个方法的迭代次数是按2的幂直到结束，所以时间复杂度为O(logn)。
         */
        while (m >= n) {
            long long t = n, i = 1;
            while ((t << 1) <= m) {
                t <<= 1;
                i <<= 1;
            }
            m -= t;
            res += i;
        }
        res *= sign;
        return res > INT32_MAX ? INT32_MAX : (int) res;
    }
};

int main() {
    std::cout << Solution().divide(5, 3) << std::endl;
    std::cout << Solution().divide(8, 2) << std::endl;
    std::cout << Solution().divide(-7, 2) << std::endl;
    std::cout << Solution().divide(-7, -2) << std::endl;
    std::cout << Solution().divide(INT32_MIN, -1) << std::endl;
    return 0;
}