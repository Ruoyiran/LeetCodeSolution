//
// Created by ranpeng on 2020/4/18.
//

#include "common.h"

// Reference: https://blog.csdn.net/chanmufeng/article/details/82955730
class Solution {
public:
    int knapSackV1(vector<int> &weights, vector<int> &values, int C) {
        return solveKS(weights, values, weights.size()-1, C);
    }

    int knapSackV2(vector<int> &weights, vector<int> &values, int C) {
        vector<vector<int>> cache(weights.size(), vector<int>(C+1, 0));
        return solveKS(weights, values, weights.size()-1, C, cache);
    }

    int knapSackV3(vector<int> &weights, vector<int> &values, int C) {
        vector<vector<int>> dp(weights.size(), vector<int>(C+1, 0));
        for (int c = 1; c <= C; ++c) {
            dp[0][c] = weights[0] <= c ? values[0] : 0;
        }
        for (int i = 1; i < weights.size(); ++i) {
            for (int c = 1; c <= C; ++c) {
                dp[i][c] = dp[i-1][c];
                if (weights[i] <= c) {
                    dp[i][c] = std::max(dp[i][c], values[i] + dp[i-1][c-weights[i]]);
                }
            }
        }
        return dp[weights.size()-1][C];
    }

    int knapsack(vector<int> &weights, vector<int> &values, int C) {
        vector<int> dp(C+1);
        for (int c = 1; c <= C; ++c) {
            dp[c] = weights[0] <= c ? values[0] : 0;
        }
        for (int i = 1; i < weights.size(); ++i) {
            for (int c = C; c >= weights[i]; --c) {
                dp[c] = std::max(dp[c], values[i]+dp[c-weights[i]]);
            }
        }
        return dp[C];
    }

    // max(F(n-1, C), Vn + F(n-1, C-Wn));
    int solveKS(vector<int> &weights, vector<int> &values, int index, int C) {
        if (index < 0 || C <= 0) {
            return 0;
        }
        // 不放index物品时所得的价值
        int res = solveKS(weights, values, index-1, C);
        if (weights[index] <= C) { // 放入第index个物品所得的价值（如果第index个物品可放得下）
            res = std::max(res, values[index] + solveKS(weights, values, index - 1, C - weights[index]));
        }
        return res;
    }

    int solveKS(vector<int> &weights, vector<int> &values, int index, int C, vector<vector<int>>& cache) {
        if (index < 0 || C <= 0) {
            return 0;
        }
        if (cache[index][C] != 0) {
            return cache[index][C];
        }
        // 不放index物品时所得的价值
        int res = solveKS(weights, values, index-1, C);
        if (weights[index] <= C) { // 放入第index个物品所得的价值（如果第index个物品可放得下）
            res = std::max(res, values[index] + solveKS(weights, values, index - 1, C - weights[index]));
        }
        cache[index][C] = res;
        return res;
    }
};

int main() {
    vector<int> weights = {2,1,3,2};
    vector<int> values = {12,10,20,15};
    int C = 5;
    cout << Solution().knapsack(weights, values, C) << endl;
}