//
// Created by ranpeng on 2020/4/18.
//

#include "common.h"

/*
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent
different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval,
CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals
that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
*/
class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> freq(26, 0);
        int maxFreq = 0, maxFreqCount = 0;
        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxFreqCount = 1;
            } else if (freq[i] == maxFreq) {
                maxFreqCount++;
            }
        }
        return std::max((int) tasks.size(), (maxFreq - 1) * (n + 1) + maxFreqCount);
    }
};

int main() {
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;
    cout << Solution().leastInterval(tasks, n) << endl;
    return 0;
}