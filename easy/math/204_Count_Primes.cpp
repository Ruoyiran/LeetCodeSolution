//
// Created by ranpeng on 2020/4/28.
//

#include "common.h"

/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/
class Solution {
public:
    // Time Limit Exceeded
    int countPrimesV1(int n) {
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime(i)) {
                ++count;
            }
        }
        return count;
    }

    // 素数是除了1和它本身之外再不能被其他数整除的自然数。
    // 厄拉多塞筛法:
    // 先将2－N的各数放入表中，然后在2的上面画一个圆圈，然后划去2的其他倍数；第一个既未画圈又没有被划去的数是3，将它画圈，再划去3的其
    // 他倍数；现在既未画圈又没有被划去的第一个数 是5，将它画圈，并划去5的其他倍数……依次类推，一直到所有小于或等于N的各数都画了圈或划
    // 去为止。这时，表中画了圈的以及未划去的那些数正好就是小于 N的素数。
    int countPrimes(int n) {
        if (n < 3) {
            return 0;
        }
        vector<bool> primes(n+1, true);
        int s = std::sqrt(n);
        for (int i = 2; i <= s; ++i) {
            if (primes[i]) {
                for (int j = i*i; j < n; j += i) {
                    primes[j] = false;
                }
            }
        }
        int count = 1; // 2 is a prime
        for (int i = 3; i < n; i += 2) {
            if (primes[i]) {
                ++count;
            }
        }
        return count;
    }
private:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i < n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << Solution().countPrimes(2) << std::endl;
    std::cout << Solution().countPrimes(10) << std::endl;
    std::cout << Solution().countPrimes(499979) << std::endl;
    return 0;
}