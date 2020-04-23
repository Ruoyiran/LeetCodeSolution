//
// Created by ranpeng on 2020/4/18.
//

#include "common.h"

/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k),
where h is the height of the person and k is the number of people in front of this person who have a height greater than
or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
class Solution {
public:
    static int cmp(const vector<int>& p1, const vector<int>& p2) {
        if (p1[0] == p2[0]) {
            return p1[1] < p2[1];
        }
        return p1[0] > p2[0];
    }

    vector<vector<int>> reconstructQueueV1(vector<vector<int>>& people) {
        if (people.empty()) {
            return {};
        }
        std::sort(people.begin(), people.end(), cmp);
        vector<vector<int>> results;
        for (auto& p : people) {
            results.insert(results.begin()+p[1], p);
        }
        return results;
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.empty()) {
            return {};
        }
        std::sort(people.begin(), people.end(), cmp);
        for (int i = 0; i < people.size(); ++i) {
            int count = 0;
            for (int j = 0; j < i; ++j) {
                if (count == people[i][1]) {
                    auto t = people[i];
                    for (int k = i-1; k >= j; --k) {
                        people[k+1] = people[k];
                    }
                    people[j] = t;
                    break;
                }
                ++count;
            }
        }
        return people;
    }
};

int main() {
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    auto res = Solution().reconstructQueue(people);
    for (auto& p : res) {
        printVector(p);
    }
    return 0;
}