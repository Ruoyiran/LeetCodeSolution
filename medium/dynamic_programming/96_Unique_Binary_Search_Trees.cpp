//
// Created by ranpeng on 2020/4/15.
//

#include "common.h"

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class Solution {
public:
    // 	Time Limit Exceeded
    int numTreesV1(int n) {
        if (n <= 1) {
            return 1;
        }
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += numTreesV1(i-1) * numTreesV1(n-i);
        }
        return sum;
    }

    // 卡特兰数
    /*
     *
     * 假设以i为根节点的种类情况为F（i，n），而G（n）为1…n的节点能组成的二叉查找树的种类。则
     * F（i，n） = G（i-1）* G（n-i）
     * 也就是左子节点以下的可能数量乘以右子节点以下的可能数量。
     * 而因为1~n都可能作为根节点，所以最终的值是它们的和，也就是
     * G（n） = F（1，n） + Ｆ（２，ｎ）　＋　……　＋Ｆ（ｎ，ｎ）
     * 换算一下就是
     * Ｇ（ｎ）　＝　Ｇ（０） * G（n-1） + G（1） * G（n-2） ＋ …… ＋ G（n-1） *Ｇ（０）
     * 其中我们可以直接看出　Ｇ（０）　＝　Ｇ（１）　＝　１。这个作为初始值来递归计算就可以了，要知道G（n），我们必须把前面的数都计算出来。
     */
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};

int main() {
    cout << Solution().numTrees(3) << endl;
    cout << Solution().numTreesV1(3) << endl;
    return 0;
}