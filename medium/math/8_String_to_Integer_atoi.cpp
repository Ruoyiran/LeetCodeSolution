//
// Created by 冉鹏 on 2020/4/28.
//

#include "common.h"

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }
        int start = 0, end = str.length()-1;
        while (start < str.length() && str[start] == ' ') {
            ++start;
        }
        while (end >= 0 && str[end] == ' ') {
            --end;
        }
        if (start > end) {
            return 0;
        }

        bool isNegative = false;
        if (str[start] == '-') {
            ++start;
            isNegative = true;
        } else if (str[start] == '+') {
            ++start;
        }
        if (start > end) {
            return 0;
        }

        int res = 0, n;
        long long t = 0;
        for (int i = start; i <= end; ++i) {
            if (str[i] < '0' || str[i] > '9') {
                break;
            }
            n = str[i] - '0';
            t = t * 10 + n;
            if (t > INT32_MAX) {
                return isNegative ? INT32_MIN : INT32_MAX;
            }
            res = (int) t;
        }
        return isNegative ? -res : res;
    }
};

int main() {
    std::cout << Solution().myAtoi("42") << std::endl;
    std::cout << Solution().myAtoi("-42") << std::endl;
    std::cout << Solution().myAtoi("2147483648") << std::endl;
    std::cout << Solution().myAtoi("21474836411") << std::endl;
    std::cout << Solution().myAtoi("-21474836411") << std::endl;
    std::cout << Solution().myAtoi("+12") << std::endl;
    std::cout << Solution().myAtoi("-12") << std::endl;
    return 0;
}
