//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

// 给定一个包含 0, 1, 2, …, n 中 n 个数的序列，找出 0 … n 中没有出现在序列中的那个数。
class Solution {
private:
    void swap(vector<int>& nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

public:
    int missingNumberV1(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i){
            while(nums[i] < nums.size() && i != nums[i])
                swap(nums, i, nums[i]);
        }
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] != i)
                return i;
        return nums.size();
    }

    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            missing = (missing ^ i ^ nums[i]);
        }
        return missing;
    }
};

int main() {
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout << Solution().missingNumber(nums) << endl;
    return 0;
}

