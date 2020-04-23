//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example1:

nums1= [1, 3]
nums2= [2]

Themedian is 2.0

Example2:

nums1= [1, 2]
nums2= [3, 4]

Themedian is (2 + 3)/2 = 2.5
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m == 0 && n == 0) {
            return 0;
        }
        if ((m+n) & 1) {
            return findKth(nums1, nums2, 0, m, 0, n, (m+n)/2+1);
        } else {
            return (findKth(nums1, nums2, 0, m, 0, n, (m+n)/2) +
                    findKth(nums1, nums2, 0, m, 0, n, (m+n)/2+1)) / 2.0;
        }
    }

private:
    /*
     二分搜索Binary Search，T：O(log(m+n))。两个有序数组A(m), B(n)，k = (m+n)/2，奇数时找k+1大的数，偶数是找第k大和第k+1大的数在除2。
     找第k((m+n)/2)大的数。先在A，B中分别找第k/2大的数，如果A[k/2-1]==B[k/2-1]，那么这个数就是两个数组中第k大的数。
     如果A[k/2-1]<B[k/2-1], 那么说明A[0]到A[k/2-1]都不可能是第k大的数，所以需要舍弃这k/2，继续从A[k/2]到A[A.length-1]继续找。
     当然，因为这里舍弃了A[0]到A[k/2-1]这k/2个数，那么第k大也就变成了第k-k/2个大的数了。
     如果 A[k/2-1]>B[k/2-1]，那么说明B[0]到B[k/2-1]都不可能是第k大的数，舍弃这k/2。
     如此迭代或者递归操作，如果有一个数组为空了，则返回另一个数组的第k大(剩下需要二分长度)的数。
     如果k==1，只需返回此时所以数中排第一小的数，就返回此时A，B中第一个元素小的那个。
     */
    int findKth(vector<int>& nums1, vector<int>& nums2, int s1, int len1, int s2, int len2, int k) {
        if (len1 > len2) {
            return findKth(nums2, nums1, s2, len2, s1, len1, k);
        }
        if (len1 == 0) {
            return nums2[s2+k-1];
        }
        if (k == 1) {
            return std::min(nums1[s1], nums2[s2]);
        }
        int k1 = std::min(k/2, len1);
        int k2 = k-k1;
        if (nums1[s1+k1-1] == nums2[s2+k2-1]) {
            return nums1[s1+k1-1];
        } else if (nums1[s1+k1-1] < nums2[s2+k2-1]) {
            return findKth(nums1, nums2, s1+k1, len1-k1, s2, len2, k-k1);
        } else {
            return findKth(nums1, nums2, s1, len1, s2+k2, len2-k2, k-k2);
        }
    }
};

int main() {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};
    cout << Solution().findMedianSortedArrays(nums1, nums2);
    return 0;
}
