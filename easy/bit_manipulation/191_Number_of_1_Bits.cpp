//
// Created by ranpeng on 2020/4/28.
//

#include "common.h"

/*
Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

Example 1:

Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.
*/
class Solution {
public:
    int hammingWeightV1(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            if (n & 0x1) {
                ++count;
            }
            n >>= 1;
        }
        return count;
    }

    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            /*
            111000 & 110111＝110000
            110000 & 101111 ＝100000
            100000 & 011111 ＝000000
            */
            n &= (n-1); // 把最右边的1清零，有多少1就清零多少次。然后累加次数
            ++count;
        }
        return count;
    }
};

int main() {
    std::cout << Solution().hammingWeight(11) << std::endl;
    std::cout << Solution().hammingWeight(0xFFFFFFFF-4) << std::endl;
    return 0;
}