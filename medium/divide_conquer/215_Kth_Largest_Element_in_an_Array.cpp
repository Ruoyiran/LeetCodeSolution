//
// Created by ranpeng on 2020/4/16.
//
#include "common.h"

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the
kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = partition(nums, left, right);
            if (mid == k - 1) return nums[mid];
            if (mid > k - 1) right = mid - 1;
            else left = mid + 1;
        }
        return 0;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = partition(nums, left, right);
            quickSort(nums, left, mid-1);
            quickSort(nums, mid+1, right);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        while (left < right) {
            while (left < right && nums[right] <= pivot) {
                --right;
            }
            if (left < right) {
                nums[left] = nums[right];
            }
            while (left < right && nums[left] >= pivot) {
                ++left;
            }
            if (left < right) {
                nums[right] = nums[left];
            }
        }
        nums[left] = pivot;
        return left;
    }
};

int main() {
    vector<int> nums = {2,1,4,5,1,2,3,5,67,7,3,5,2,4,8};
    Solution solution;
    cout << solution.findKthLargest(nums, 2) << endl;
    solution.quickSort(nums, 0, nums.size()-1);
    printVector(nums);
}
