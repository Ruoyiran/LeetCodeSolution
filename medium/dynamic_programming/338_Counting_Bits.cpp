//
// Created by ranpeng on 2020/4/17.
//

#include "common.h"

/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in
their binary representation and return them as an array.

Example:

For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /
possibly in a single pass?

Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
 */
class Solution {
public:
    // O(n*sizeof(integer))
    vector<int> countBitsV1(int num) {
        vector<int> bits(num+1, 0);
        for (int i = 0; i <= num; ++i) {
            bits[i] = countOne(i);
        }
        return bits;
    }

    int countOne(int n) {
        int count = 0;
        while (n > 0) {
            if ((n & 1) == 1) {
                ++count;
            }
            n >>= 1;
        }
        return count;
    }

    // using __builtin_popcount
    vector<int> countBitsV2(int num) {
        vector<int> bits(num+1, 0);
        for (int i = 0; i <= num; ++i) {
            bits[i] = __builtin_popcount(i);
        }
        return bits;
    }

    vector<int> countBits(int num) {
        /*
            0 : (0<<1) + 0
            1 : (0<<1) + 1
            2 : (1<<1) + 0
            3 : (1<<1) + 1
            4 : (2<<1) + 0
            5 : (2<<1) + 1
            6 : (3<<1) + 0
            7 : (3<<1) + 1
         */
        vector<int> bits(num+1, 0);
        for (int i = 1; i <= num; ++i) {
            bits[i] = bits[i>>1] + i % 2;
        }
        return bits;
    }
};

int main() {
    auto results = Solution().countBits(7);
    printVector(results);
    return 0;
}