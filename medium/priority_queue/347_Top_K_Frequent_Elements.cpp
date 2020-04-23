//
// Created by ranpeng on 2020/4/17.
//
#include "common.h"

/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto n : nums) {
            ++m[n];
        }
        priority_queue<pair<int, int>> q;
        for (auto& p : m) {
            q.push({p.second, p.first});
        }
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};

int main() {
    vector<int> nums = {3,3,3,1,1,1,2,2,3};
    int k =2;
    auto res = Solution().topKFrequent(nums, k);
    printVector(res);
    return 0;
}