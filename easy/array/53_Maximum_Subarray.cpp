//
// Created by ranpeng on 2020/4/12.
//

#include "common.h"

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0], tmp = 0, maxSum = 0;
        for (int v : nums) {
            max = std::max(max, v);
            tmp += v;
            if (tmp < 0) {
                tmp = 0;
            }
            maxSum = std::max(maxSum, tmp);
        }
        if (max < 0) {
            return max;
        }
        return maxSum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = solution.maxSubArray(nums);
    cout << result << endl;
}