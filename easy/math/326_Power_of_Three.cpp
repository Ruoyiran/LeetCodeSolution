//
// Created by ranpeng on 2020/4/28.
//

#include "common.h"

/*
Given an integer, write a function to determine if it is a power of three.

Example 1:

Input: 27
Output: true
Example 2:

Input: 0
Output: false
Example 3:

Input: 9
Output: true
Example 4:

Input: 45
Output: false
*/

class Solution {
public:
    bool isPowerOfThreeV1(int n) {
        while (n > 1 && n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }

    bool isPowerOfThree(int n) {
        int pow3_19 = 1162261467; // 3^19;
        if (n < 1 || n > pow3_19) {
            return false;
        }
        return pow3_19 % n == 0;
    }
};

int main() {
    std::cout << Solution().isPowerOfThree(9) << std::endl;
    std::cout << Solution().isPowerOfThree(45) << std::endl;
    std::cout << Solution().isPowerOfThree(27) << std::endl;
    std::cout << Solution().isPowerOfThree(INT32_MAX) << std::endl;
    return 0;
}