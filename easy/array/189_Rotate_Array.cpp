//
// Created by ranpeng on 2020/4/28.
//

#include "common.h"

/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/
class Solution {
public:
    void rotateV1(vector<int>& nums, int k) {
        k %= nums.size();
        int left = 0, right = nums.size()-1;
        int i = 0;
        while (left < right && i < k) {
            std::swap(nums[left++], nums[right--]);
            ++i;
        }
        std::reverse(nums.begin(), nums.begin()+k);
        std::reverse(nums.begin()+k, nums.end()-k);
        std::reverse(nums.begin()+k, nums.end());
    }

    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        std::reverse(nums.begin(), nums.end()-k);
        std::reverse(nums.end()-k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};

int main() {
    std::vector<int> nums = {1,2,3,4,5,6,7,8};
    Solution().rotate(nums, 1);
    printVector(nums);
    return 0;
}

