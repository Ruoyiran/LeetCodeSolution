//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/
class Solution {
public:
    static int comp(int& a, int b) {
        string s1 = std::to_string(a) + std::to_string(b);
        string s2 = std::to_string(b) + std::to_string(a);
        return s1 > s2;
    }

    string largestNumber(vector<int>& nums) {
        if (nums.empty()) {
            return "";
        }
        std::sort(nums.begin(), nums.end(), comp);
        if (nums[0] == 0) {
            return "0";
        }
        string res;
        for(int n : nums) {
            res.append(std::to_string(n));
        }
        return res;
    }
};

int main() {
    vector<int> nums = {10,9, 100, 93, 91, 991, 0};
    std::cout << Solution().largestNumber(nums) << std::endl;
    return 0;
}