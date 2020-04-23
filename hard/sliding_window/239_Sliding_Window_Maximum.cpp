//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

Follow up:
Could you solve it in linear time?

Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7]
Explanation:

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 */
class Solution {
public:
    vector<int> maxSlidingWindowV1(vector<int>& nums, int k) {
        if (nums.empty() || k < 1) {
            return {};
        }
        if (nums.size() < k) {
            return {*std::max_element(nums.begin(), nums.end())};
        }
        vector<int> res;
        int start = 0, end = start+k;
        while (end <= nums.size()) {
            res.push_back(*std::max_element(nums.begin()+start, nums.begin()+end));
            ++start;
            ++end;
        }
        return res;
    }

    vector<int> maxSlidingWindowV2(vector<int>& nums, int k) {
        if (nums.empty() || k < 1) {
            return {};
        }
        if (nums.size() < k) {
            return {*std::max_element(nums.begin(), nums.end())};
        }
        priority_queue<pair<int, int>> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && q.top().second <= i-k) {
                q.pop();
            }
            q.push({nums[i], i});
            if (i >= k-1) {
                res.push_back(q.top().first);
            }
        }
        return res;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || k < 1) {
            return {};
        }
        if (nums.size() < k) {
            return {*std::max_element(nums.begin(), nums.end())};
        }
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (!q.empty() && q.front() == i-k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k-1) {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto res = Solution().maxSlidingWindow(nums, 3);
    printVector(res);
    return 0;
}