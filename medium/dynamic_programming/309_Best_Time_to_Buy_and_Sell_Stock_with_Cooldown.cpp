//
// Created by ranpeng on 2020/4/17.
//

#include "common.h"

/*
用一个数组表示股票每天的价格，数组中第i个数表示股票在第i天的价格。 可以进行多次交易，但在存在两个限制条件：1）不可以同时进行多次交易
（必须卖出股票前再买一次股票）；2）售出股票后，不能在第二天在买股票（冷冻期）；求此时的最大收益。
 */
class Solution {
public:
    int maxProfitV1(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        /*
         * buy[i]表示在第i天之前最后一个操作是买，此时的最大收益。
         * sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益。
         * rest[i]表示在第i天之前最后一个操作是冷冻期，此时的最大收益。
         */
        vector<int> buy(prices.size()+1, 0);
        vector<int> sell(prices.size()+1, 0);
        vector<int> rest(prices.size()+1, 0);
        buy[1] = -prices[0]; // 需要先买再卖
        for (int i = 2; i <= prices.size(); ++i) {
            // 第i天买：前一天休息的最大收益-股票当天的价格，前一天买的最大收益
            buy[i] = std::max(rest[i-1]-prices[i-1], buy[i-1]);
            // 第i天卖：前一天买的最大收益+股票当天的价格，前一天卖的最大收益
            sell[i] = std::max(buy[i-1]+prices[i-1], sell[i-1]);
            // 第i天休息：前一天操作是买的最大收益，前一天操作是卖的最大收益，前一天休息的最大收益
            rest[i] = std::max(std::max(sell[i-1], buy[i-1]), rest[i-1]);
        }
        return sell[prices.size()];
    }

    int maxProfitV2(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        /*
         * buy[i]表示在第i天之前最后一个操作是买，此时的最大收益。
         * sell[i]表示在第i天之前最后一个操作是卖，此时的最大收益。
         * 如果第i天休息，那么第i天休息的最大收益等于第i-1天卖出的最大收益
         */
        vector<int> buy(prices.size()+1, 0);
        vector<int> sell(prices.size()+1, 0);
        buy[1] = -prices[0];
        for (int i = 2; i <= prices.size(); ++i) {
            // 第i天买：前一天休息的最大收益-股票当天的价格，前一天买的最大收益
            buy[i] = std::max(sell[i-2]-prices[i-1], buy[i-1]);
            // 第i天卖：前一天买的最大收益+股票当天的价格，前一天卖的最大收益
            sell[i] = std::max(buy[i-1]+prices[i-1], sell[i-1]);
        }
        return sell[prices.size()];
    }

    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }
        int sell = 0, buy = INT32_MIN, prevBuy = 0, prevSell = 0;
        for (int price : prices) {
            prevBuy = buy;
            buy = std::max(prevSell-price, buy);
            prevSell = sell;
            sell = std::max(prevBuy+price, sell);
        }
        return sell;
    }
};

int main() {
    vector<int> nums = {1,2,4};
    cout << Solution().maxProfit(nums) << endl;
    return 0;
}
