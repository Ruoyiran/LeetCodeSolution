//
// Created by ranpeng on 2020/4/27.
//

#include "common.h"

/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array
contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            return {};
        }
        vector<int> res(digits.begin(), digits.end());
        int carry = 1;
        for (int i = res.size()-1; i >= 0; --i) {
            if (carry < 1) {
                return res;
            }
            int sum = res[i] + carry;
            carry = sum/10;
            res[i] = sum % 10;
        }
        if (carry > 0) {
            res.insert(res.begin(), carry);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {9,9,9};
    auto res = Solution().plusOne(nums);
    printVector(res);
    return 0;
}