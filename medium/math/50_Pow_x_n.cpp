//
// Created by 冉鹏 on 2020/4/28.
//

#include "common.h"

/*
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double base = (n & 0x1) ? x : 1.0;
        int m = n/2;
        if (n < 0) {
            m = -m;
            x = 1/x;
            base = 1/base;
        }
        return base * myPow(x*x, m);
    }
};

int main() {
    std::cout << Solution().myPow(2, -2) << std::endl;
    std::cout << Solution().myPow(-1, -2) << std::endl;
    std::cout << Solution().myPow(0, -2) << std::endl;
    std::cout << Solution().myPow(0, 2) << std::endl;
    std::cout << Solution().myPow(2, -2) << std::endl;
    std::cout << Solution().myPow(2.1, 3) << std::endl;
    std::cout << Solution().myPow(1.0, INT32_MIN) << std::endl;
    std::cout << Solution().myPow(2.1, 3) << std::endl;
    std::cout << Solution().myPow(2, 10) << std::endl;
    std::cout << Solution().myPow(2, -10) << std::endl;
}
