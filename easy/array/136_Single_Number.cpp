//
// Created by ranpeng on 2020/4/12.
//
#include "common.h"

// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
class Solution {
public:
    int singleNumberV1(vector<int> &nums) {
        int single = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            single ^= nums[i];
        }
        return single;
    }

    int singleNumber(vector<int> &nums) {
        set<int> s;
        int total1 = 0;
        int total2 = 0;
        for (int v : nums) {
            if (s.find(v) == s.end()) {
                total2 += v;
                s.insert(v);
            }
            total1 += v;
        }
        return 2 * total2 - total1;
    }
};

int main() {
    vector<int> nums = {4,1,2,1,2};
    Solution solution;
    cout << solution.singleNumber(nums) << endl;
    return 0;
}