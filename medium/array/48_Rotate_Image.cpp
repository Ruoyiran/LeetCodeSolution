//
// Created by ranpeng on 2020/4/14.
//

#include "common.h"

/*
Rotate Image

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > n-j-1) {
                    continue;
                }
                swap(matrix, {i, j}, {n-j-1, n-i-1});
            }
        }

        for (int i = 0; i < n/2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix, {i, j}, {n-i-1, j});
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
            { 5, 1, 9,11},
            { 2, 4, 8,10},
            {13, 3, 6, 7},
            {15,14,12,16}
    };
    for (auto r : matrix) {
        printVector(r);
    }
    Solution().rotate(matrix);
    cout << "after rotate:" << endl;
    for (auto r : matrix) {
        printVector(r);
    }
    return 0;
}