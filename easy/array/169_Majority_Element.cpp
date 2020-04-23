//
// Created by ranpeng on 2020/4/12.
//
#include "common.h"

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Input: [3,2,3]
Output: 3
 */
class Solution {
public:
    int majorityElementV1(vector<int>& nums) {
        map<int, int> counter;
        for (int v : nums) {
            if (counter.find(v) == counter.end()) {
                counter[v] = 1;
            } else {
                counter[v] += 1;
            }
        }
        auto iter = counter.begin();
        int maxCount = 0;
        int target = 0;
        while (iter != counter.end()) {
            if (iter->second > maxCount) {
                target = iter->first;
                maxCount = iter->second;
            }
            ++iter;
        }
        return target;
    }

    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority = 0;
        for (int v : nums) {
            if (count == 0) {
                majority = v;
            }
            count += majority == v ? 1 : -1;
        }
        return majority;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 2, 3};
    cout << solution.majorityElement(nums) << endl;
    return 0;
}
