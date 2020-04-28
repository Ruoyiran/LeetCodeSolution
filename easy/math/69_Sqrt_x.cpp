//
// Created by ranpeng on 2020/4/27.
//

#include "common.h"

/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
*/
class Solution {
public:
    int mySqrtV1(int x) {
        int left = 1;  // left不能取0;因为如果x=1，那么（0+1）/2 = 0，导致mid等于0，做除法的时候会报错
        int right = x;
        while (left <= right) {
            // int mid = (left + right) / 2;  ——> 不要这么写，是因为如果right很大，left+right可能会超过整型最大值
            int mid = left + (right - left) / 2;
            if (mid == x / mid) {
                return mid;
            }
            else if (mid > x / mid) {
                right = mid - 1;
            }
            else {  // mid < x / mid
                left = mid + 1;
            }
        }
        return right;
    }

    // newton's method
    int mySqrt(int x) {
        long long v = (long long)x;
        while (v*v>x) {
            v = (v+x/v)>>1;
        }
        return v;
    }
};

int main() {
    std::cout << Solution().mySqrt(4) << std::endl;
    return 0;
}