//
// Created by ranpeng on 2020/4/16.
//

#include "common.h"

/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
 */
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j]) {
                    continue;
                }
                if (grid[i][j] == '1') {
                    traverse(grid, i, j, visited);
                    ++count;
                }
            }
        }
        return count;
    }

    void traverse(const vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) {
            return;
        }
        if (grid[i][j] == '0') {
            return;
        }
        if (visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        traverse(grid, i+1, j, visited);
        traverse(grid, i, j+1, visited);
        traverse(grid, i-1, j, visited);
        traverse(grid, i, j-1, visited);
    }
};

int main() {
    vector<vector<char>> nums = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0'},
    };
    cout << Solution().numIslands(nums) << endl;
    return 0;
}