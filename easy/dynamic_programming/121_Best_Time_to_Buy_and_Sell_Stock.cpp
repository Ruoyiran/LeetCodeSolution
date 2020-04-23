//
// Created by ranpeng on 2020/4/12.
//
#include "common.h"

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
design an algorithm to find the maximum profit.
 */
class Solution {
public:
    // Time Limit Exceeded
    int maxProfitV1(vector<int>& prices) {
        int maxValue = 0;
        for (int i = 0; i < prices.size()-1; ++i) {
            for (int j = i+1; j < prices.size(); ++j) {
                maxValue = std::max(maxValue, prices[j]-prices[i]);
            }
        }
        return maxValue;
    }

    int maxProfit(vector<int>& prices) {
        int minValue = INT32_MAX;
        int maxValue = 0;
        for (int p : prices) {
            minValue = std::min(minValue, p);
            maxValue = std::max(maxValue, p-minValue);
        }
        return maxValue;
    }
};

int main() {
    vector<int> nums = {7,1,5,3,6,4};
    Solution solution;
    cout << solution.maxProfit(nums);
    return 0;
}