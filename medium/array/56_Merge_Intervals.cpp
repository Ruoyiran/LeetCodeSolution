//
// Created by ranpeng on 2020/4/14.
//

#include "common.h"
static int cmp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        std::sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> results;
        for (auto& interval : intervals) {
            if (results.empty()) {
                results.push_back(interval);
                continue;
            }
            auto &last = results.back();
            if (interval[0] > last[1]) {
                results.push_back(interval);
            } else {
                last[1] = std::max(last[1], interval[1]);
            }
        }
        return results;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,4},{2,3}};
    auto results = Solution().merge(intervals);
    for (auto &r : results) {
        printVector(r);
    }
    return 0;
}