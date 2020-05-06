//
// Created by ranpeng on 2020/5/6.
//

#include "common.h"

/*
Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?
*/
class Solution {
public:
    vector<int> getRowV1(int rowIndex) {
        if (rowIndex < 0) {
            return {};
        }
        vector<int> res(rowIndex+1, 1);
        int index = 2;
        while (index <= rowIndex) {
            auto prev = res;
            for (int i = 1; i < index; ++i) {
                res[i] = prev[i-1] + prev[i];
            }
            ++index;
        }
        return res;
    }

    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return {};
        }
        vector<int> res(rowIndex+1, 1);
        int index = 2;
        while (index <= rowIndex) {
            int pre = res[0];
            for (int i = 1; i < index; ++i) {
                int t = pre + res[i];
                pre = res[i];
                res[i] = t;
            }
            ++index;
        }
        return res;
    }
};

int main() {
    auto res = Solution().getRow(4);
    printVector(res);
    return 0;
}