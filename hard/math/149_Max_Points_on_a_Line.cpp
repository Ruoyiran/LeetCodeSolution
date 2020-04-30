//
// Created by ranpeng on 2020/4/30.
//

#include "common.h"

/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Example 1:

Input: [[1,1],[2,2],[3,3]]
Output: 3
Explanation:
^
|
|        o
|     o
|  o
+------------->
0  1  2  3  4
Example 2:

Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
Output: 4
Explanation:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            map<pair<int, int>, int> hash;
            // duplicates的初始值是1: 在 i 的循环内，对每一个在 i 后面的点 j 之间的slope计数，最后提取出的结果是和 i 共线的其他点数，
            // 还没有算 i 自己。而其他所有和 i 重合的点，也都应该一起被计数。
            int duplicates = 1;
            int current = 0;
            for (int j = i + 1; j < n; j++) {
                // slope的计算：要处理三种特殊情况，首先排除duplicates，然后是vertical，直接返回{x, 0}, 如果是horizontal，
                // 直接返回{0 , y}，否者 要将slope pair用gcd函数的返回值normalize一下再返回主函数，存进 hash。
                if (points[i] == points[j]) {
                    duplicates++;
                } else {
                    pair<int, int> slope = getSlope(points[i], points[j]);
                    hash[slope]++;
                    current = max(current, hash[slope]);
                }
            }
            result = max(result, current + duplicates);
        }
        return result;
    }

    pair<int, int> getSlope(vector<int> & a, vector<int> & b) {
        // vertical line
        if (a[0] == b[0]) return {a[0], 0};
        // horizontal line
        if (a[1] == b[1]) return {0, a[1]};
        // find gcd
        int d = gcd(a[1] - b[1], a[0] - b[0]);
        // return normalized slope pair
        return {(a[1] - b[1]) / d, (a[0] - b[0]) / d};
    }

    int gcd(int m, int n){
        return (n == 0) ? m : gcd(n, m % n);
    }
};

int main() {
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    std::cout << Solution().maxPoints(points) << std::endl;
    return 0;
}