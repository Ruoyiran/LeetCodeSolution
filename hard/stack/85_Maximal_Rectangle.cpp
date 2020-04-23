//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
 ["1","0","1","0","0"],
 ["1","0","1","1","1"],
 ["1","1","1","1","1"],
 ["1","0","0","1","0"]
]
Output: 6
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        vector<int> heights;
        int res = 0;
        for(auto& row : matrix) {
            heights.resize(row.size());
            for (int i = 0; i < row.size(); ++i) {
                heights[i] = row[i] == '0' ? 0 : heights[i]+1;
            }
            res = std::max(res, largestRectangleArea(heights));
        }
        return res;
    }

private:
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
    vector<vector<char>> matrix = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
    };
    cout << Solution().maximalRectangle(matrix) << endl;
    return 0;
}