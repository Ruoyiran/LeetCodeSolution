//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in
the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.
*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        /*
         使用一个最大堆，然后遍历数组每一个元素，将其加入堆，根据最大堆的性质，大的元素会排到最前面，然后我们看当前堆中的元素个数是否大于k，
         大于的话就将首元素去掉，循环结束后我们返回堆中的首元素即为所求
         */
        int rows = matrix.size();
        int cols = matrix[0].size();
        priority_queue<int> q;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                q.push(matrix[r][c]);
                if (q.size() > k) {
                    q.pop();
                }
            }
        }
        return q.top();
    }
};

int main() {
    vector<vector<int>> matrix =  {
            { 1,  5,  9},
            {10, 11, 13},
            {12, 13, 15}
    };
    std::cout << Solution().kthSmallest(matrix, 4) << std::endl;
}