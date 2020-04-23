//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it
is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
section) are being trapped. Thanks Marcos for contributing this image!
*/
class Solution {
public:
    int trap(vector<int> &height) {
        int left = 0, right = height.size()-1;
        int area = 0, curr = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                curr = height[left];
                while (left < right && height[left] <= curr) {
                    area += curr - height[left];
                    ++left;
                }
            } else {
                curr = height[right];
                while (left < right && height[right] <= curr) {
                    area += curr - height[right];
                    --right;
                }
            }
        }
        return area;
    }
};

int main() {
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution().trap(nums) << endl;
    return 0;
}