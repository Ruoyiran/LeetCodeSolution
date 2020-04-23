//
// Created by ranpeng on 2020/4/12.
//

#include "common.h"
int jiecheng(int n) {
    int r = 1;
    for (int i = n; i >= 1; --i) {
        r *= i;
    }
    return r;
}

int C(int n, int m) {
    if (m > n) {
        return 0;
    }
    return jiecheng(n) / (jiecheng(m) * jiecheng(n-m));
}

// 每次只能上一级或者两级台阶，求上n级台阶的方法个数
class Solution {
public:
    // Runtime Error
    int climbStairsV1(int n) {
        if (n < 1) {
            return 0;
        }
        int n_two = n/2;
        int total = 0;
        while (n_two >= 0) {
            int n_one = (n - n_two*2);
            int num = n_one + n_two;
            total += C(num, n_two);
            --n_two;
        }
        return total;
    }

    // Time Limit Exceeded
    int climbStairsV2(int i, int n) {
        if (i > n) {
            return 0;
        }
        if (n == i) {
            return 1;
        }
        return climbStairsV2(i + 1, n) + climbStairsV2(i + 2, n);
    }

    int climbStairs(int i, int n, vector<int>& cache) {
        if (i > n) {
            return 0;
        }
        if (n == i) {
            return 1;
        }
        if (cache[i] > 0) {
            return cache[i];
        }
        cache[i] = climbStairs(i + 1, n, cache) + climbStairs(i + 2, n, cache);
        return cache[i];
    }

    int climbStairsV3(int n) {
        vector<int> cache(n+1);
        return climbStairs(0, n, cache);
    }

    int climbStairs(int n) {
        if (n <= 1) {
            return 1;
        }
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    cout << solution.climbStairs(0) << endl;
    cout << solution.climbStairs(2) << endl;
    cout << solution.climbStairs(3) << endl;
    cout << solution.climbStairs(4) << endl;
    cout << solution.climbStairs(5) << endl;
    cout << solution.climbStairs(6) << endl;
    cout << solution.climbStairs(10) << endl;
    cout << solution.climbStairs(15) << endl;
    cout << solution.climbStairs(20) << endl;
}