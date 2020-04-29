//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example 1:

Input: nums = [1, 5, 1, 1, 6, 4]
Output: One possible answer is [1, 4, 1, 5, 1, 6].
Example 2:

Input: nums = [1, 3, 2, 2, 3, 1]
Output: One possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?
*/
class Solution {
public:
    /*
     遍历数组的时候如果当前的数大于中位数就将其从左往右放奇数位置, 如果小于中位数就将其从右往左放在偶数位置. 这样还需要解决的一个问题是
     如何可以互不干扰的放到正确位置. 举个栗子: 1, 1, 2, 2, 2, 3这六个数:
     我们可以按照这样一个顺序将数组索引拉开成这样: 1, 3, 5, 0, 2, 4, 也就是我们可以按照这样一个顺序来遍历数组, 同时维护一个低位指针
     用来代表奇数位置已经放到哪里, 和一个高位指针来表示偶数位置已经放到哪里, 这样在我们遍历数组的每一个元素的时候就可以按照这样的方式将
     元素分别放高位还是低位. 而要将数组按照这样索引的方式遍历我们只需要一个映射即可, 即(2*i+1)%(len|1).
    */
    void wiggleSort(vector<int>& nums) {
        std::nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        int n = nums.size();
        int mid = nums[n/2];
        auto index = [n](int pos){ return (1 + pos*2) % (n | 1); };
        int low = 0, high = n - 1, i = 0;
        while (i <= high) {
            if (nums[index(i)] < mid) { // 小于中位数就将其从右往左放在偶数位置
                std::swap(nums[index(i)], nums[index(high--)]);
            } else if (nums[index(i)] > mid) { // 大于中位数就将其从左往右放奇数位置
                std::swap(nums[index(i)], nums[index(low++)]);
            } else {
                ++i;
            }
        }
    }
};

int main() {
    vector<int> nums = {3, 5, 2, 1, 4,6,7,8,9,10};
    Solution().wiggleSort(nums);
    printVector(nums);
    return 0;
}