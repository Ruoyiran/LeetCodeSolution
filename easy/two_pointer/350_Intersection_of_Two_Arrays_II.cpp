//
// Created by ranpeng on 2020/4/28.
//

#include "common.h"

/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.


Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the
memory at once?
*/
class Solution {
public:
    // hash table
    vector<int> intersectV1(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (auto n : nums1) {
            m[n]++;
        }
        vector<int> res;
        for(auto n : nums2) {
            if (m[n]-- > 0) {
                res.push_back(n);
            }
        }
        return res;
    }

    // binary search
    vector<int> intersectV2(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return intersectV2(nums2, nums1);
        }
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0;
        while (i < nums1.size()) {
            int count1 = 1;
            while (i < nums1.size()-1 && nums1[i] == nums1[i+1]) {
                ++i;
                ++count1;
            }
            int pos = binarySearch(nums2, nums1[i]);;
            if (pos == -1) {
                ++i;
                continue;
            }
            int count2 = 1;
            int k = pos;
            while (k > 0 && nums2[k] == nums2[k-1]) {
                --k;
                ++count2;
            }
            k = pos;
            while (k < nums2.size()-1 && nums2[k] == nums2[k+1]) {
                ++k;
                ++count2;
            }
            int min = std::min(count1, count2);
            for (int j = 0; j < min; ++j) {
                res.push_back(nums1[i]);
            }
            ++i;
        }
        return res;
    }

    // two-pointer
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                ++i;
                ++j;
            } else if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return res;
    }

private:
    int binarySearch(const vector<int>& nums, int target) {
        if (nums.empty() || target < nums[0] || target > nums[nums.size() - 1]) {
            return -1;
        }
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    auto res = Solution().intersect(nums1, nums2);
    printVector(res);
    return 0;
}