//
// Created by ranpeng on 2020/4/13.
//

#include "common.h"

/*
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines
are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.

Note: You may not slant the container and nis at least 2.
 */
class Solution {
public:
    // Time Limit Exceeded
    int maxAreaV1(vector<int>& height) {
        int max = 0;
        for (int i = 0; i < height.size(); ++i) {
            for (int j = height.size()-1; j > i; --j) {
                int w = j-i;
                int h = std::min(height[i], height[j]);
                max = std::max(max, w*h);
            }
        }
        return max;
    }

    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int max = 0;
        while (i < j) {
            int w = j-i;
            int h = std::min(height[i], height[j]);
            max = std::max(max, w*h);
            if (height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return max;
    }
};

int main() {
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    Solution solution;
    cout << solution.maxArea(nums) << endl;
}