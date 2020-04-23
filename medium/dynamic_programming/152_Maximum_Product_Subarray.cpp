//
// Created by ranpeng on 2020/4/16.
//

#include "common.h"

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        vector<int> dpMax(nums.size());
        vector<int> dpMin(nums.size());
        int max = INT32_MIN;
        dpMax[0] = dpMin[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dpMax[i] = std::max(std::max(dpMax[i-1]*nums[i], nums[i]), dpMin[i-1]*nums[i]);
            dpMin[i] = std::min(std::min(dpMin[i-1]*nums[i], nums[i]), dpMax[i-1]*nums[i]);
            max = std::max(dpMax[i], max);
        }
        return max;
    }
};

int main() {
    vector<int> nums = {2,3,-2,4};
    cout << Solution().maxProduct(nums) << endl;
    return 0;
}