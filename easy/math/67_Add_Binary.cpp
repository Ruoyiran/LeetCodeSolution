//
// Created by ranpeng on 2020/5/6.
//

#include "common.h"

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length()-1, n = b.length()-1;
        string res;
        int carry = 0;
        while (m >= 0 || n >= 0) {
            int sum = carry;
            if (m >= 0) {
                sum += a[m] - '0';
                --m;
            }
            if (n >= 0) {
                sum += b[n] - '0';
                --n;
            }
            res.push_back((sum % 2) + '0');
            carry = sum/2;
        }
        if (carry > 0) {
            res.push_back(carry+'0');
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    std::cout << Solution().addBinary("11", "1") << std::endl;
    std::cout << Solution().addBinary("1010", "1011") << std::endl;
    return 0;
}