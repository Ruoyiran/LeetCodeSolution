//
// Created by ranpeng on 2020/4/28.
//

#include "common.h"

/*
Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
*/

class Solution {
public:
    // Time Limit Exceeded
    int trailingZeroesV1(int n) {
        int res = 0;
        for (int i = 5; i <= n; i+=5) {
            res += countFive(i);
        }
        return res;
    }

    int countFive(int n) {
        int count = 0;
        while (n % 5 == 0) {
            ++count;
            n /= 5;
        }
        return count;
    }

    int trailingZeroes(int n) {
        int count = 0;
        while (n >= 5) {
            n /= 5;
            count += n;
        }
        return count;
    }
};

int main() {
    std::cout << Solution().trailingZeroes(100) << std::endl;
    std::cout << Solution().trailingZeroes(99) << std::endl;
    std::cout << Solution().trailingZeroes(2147483647) << std::endl;
    return 0;
}