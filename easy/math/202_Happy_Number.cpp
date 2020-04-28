//
// Created by ranpeng on 2020/4/28.
//

#include "common.h"

/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by
the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops
endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example:

Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
 */
class Solution {
public:
    bool isHappyV1(int n) {
        set<int> s;
        while (s.find(n) == s.end() && n != 1) {
            s.insert(n);
            n = getNext(n);
        }
        return n == 1;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        } while (slow != fast); // detect cycle
        return slow == 1;
    }

    int getNext(int n) {
        int t = 0;
        while (n > 0) {
            t += (n%10) * (n%10);
            n /= 10;
        }
        return t;
    }
};

int main() {
    std::cout << Solution().isHappy(19) << std::endl;
    return 0;
}