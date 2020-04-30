//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/
class Solution {
public:
    Solution(vector<int>& nums) : _originalNums(nums), _nums(nums) {
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        _nums = _originalNums;
        return _originalNums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> indexes(_nums.size());
        for (int i = 0; i < indexes.size(); ++i) {
            indexes[i] = i;
        }
        vector<int> res;
        res.reserve(_nums.size());
        while (!indexes.empty()) {
            int pos = rand() % indexes.size();
            int index = indexes[pos];
            res.push_back(_nums[index]);
            std::swap(indexes[pos], indexes[indexes.size()-1]);
            indexes.pop_back();
        }
        return res;
    }

private:
    vector<int> _nums;
    vector<int> _originalNums;
};

int main() {
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    Solution solution(nums);
    printVector(solution.shuffle());
    printVector(solution.reset());
    printVector(solution.shuffle());
    return 0;
}