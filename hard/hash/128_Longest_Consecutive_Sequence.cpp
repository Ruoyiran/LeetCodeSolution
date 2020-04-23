//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> s;
        for (auto n : nums) {
            s.insert(n);
        }
        int res = 0;
        while (!s.empty()) {
            int n = *s.begin(); s.erase(s.begin());
            int smaller = n-1;
            int bigger = n+1;
            int count = 1;
            while (s.find(smaller) != s.end()) {
                s.erase(smaller);
                ++count;
                --smaller;
            }

            while (s.find(bigger) != s.end()) {
                s.erase(bigger);
                ++count;
                ++bigger;
            }
            res = std::max(res, count);
        }
        return res;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << Solution().longestConsecutive(nums) << endl;
    return 0;
}
