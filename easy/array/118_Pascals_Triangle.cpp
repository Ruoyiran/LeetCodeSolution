//
// Created by ranpeng on 2020/4/27.
//

#include "common.h"

/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows < 1) {
            return {};
        }
        vector<vector<int>> res(numRows);
        for (int i = 1; i <= numRows; ++i) {
            auto& cols = res[i-1];
            cols.assign(i, 1);
            for (int j = 1; j < i-1; ++j) {
                cols[j] = res[i-2][j-1] + res[i-2][j];
            }
        }
        return res;
    }
};

int main() {
    auto res = Solution().generate(5);
    for (auto& r : res) {
        printVector(r);
    }
    return 0;
}