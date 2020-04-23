//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of
largest rectangle in the histogram.
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/
class Solution {
public:
    int largestRectangleAreaV1(vector<int>& heights) {
        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            if (i+1 < heights.size() && heights[i] <= heights[i+1]) {
                continue;
            }
            int minH = heights[i];
            for (int j = i; j >= 0; --j) {
                minH = std::min(minH, heights[j]);
                res = std::max(res, minH * (i-j+1));
            }
        }
        return res;
    }

    int largestRectangleAreaV2(vector<int>& heights) {
        stack<int> s;
        int res = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            if (s.empty() || heights[s.top()] < heights[i]) {
                s.push(i);
            } else {
                int h = heights[s.top()]; s.pop();
                int w = s.empty() ? i : i-s.top()-1;
                res = std::max(res, w*h);
                --i;
            }
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int res = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int h = heights[s.top()]; s.pop();
                res = std::max(res, h * (s.empty() ? i : (i-s.top()-1)));
            }
            s.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2,1,5,6,2,3};
    cout << Solution().largestRectangleArea(nums) << endl;
    return 0;
}
