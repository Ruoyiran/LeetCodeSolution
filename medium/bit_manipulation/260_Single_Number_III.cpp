//
// Created by 冉鹏 on 2020/5/6.
//

#include "common.h"

/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly
twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2);
        int t = 0;
        for (int n : nums) {
            t ^= n;
        }
        /*
           假设nums中2个不同的数为a和b，通过计算nums的异或运算就能求出a和b的异或值，定为c。那么c的二进制表示中，从右开始数的第一个1即为a和b的二进制形式在该位上肯定是不同的值。
           假如a = 0101, b = 0011, 那么a^b=0110, 那么a和b是在从右往左数的第二位值不同。设置bit=010，将nums里的每个数&bit, 便可将nums分成2组了，每组的异或值就是a或者b了。
        */
        int diffBit = 1;
        while ((t & 0x1) == 0) {
            diffBit <<= 1;
            t >>= 1;
        }
        for (int n : nums) {
            if ((n & diffBit) == 0) {
                res[0] ^= n;
            } else {
                res[1] ^= n;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,2,1,3,2,5};
    auto res = Solution().singleNumber(nums);
    printVector(res);
    return 0;
}