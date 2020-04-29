//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/
class Solution {
public:
    int calculate(string s) {
        int num = 0;
        stack<int> nums;
        unordered_set<char> operators = {'+', '-', '*', '/'};
        char prevOp = '+';
        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (std::isdigit(c)) {
                num = num * 10 + (c - '0'); // 考虑数值溢出问题，或写为num * 10 - '0' + c;
            }
            // 遇到符号或者最字符串结尾
            // 前一个符号如果是'+'，那么数字入栈，如果前一个符号为'-'，那么数字取相反数入栈
            // 如果前一个符号是'*"或'/'，则取出栈顶数字，与当前数字进行'*'或'/'，再将运算结果入栈
            if (operators.find(c) != operators.end() || i == s.length()-1) {
                if (prevOp == '+') {
                    nums.push(num);
                } else if (prevOp == '-') {
                    nums.push(-num);
                } else if (prevOp == '*') {
                    int t = nums.top(); nums.pop();
                    nums.push(t * num);
                } else if (prevOp == '/') {
                    int t = nums.top(); nums.pop();
                    nums.push(t / num);
                }
                prevOp = c;
                num = 0;
            }
        }
        int res = 0;
        // 栈内保存的所有数字均为'+'运算
        while (!nums.empty()) {
            res += nums.top(); nums.pop();
        }
        return res;
    }
};

int main() {
//    std::cout << Solution().calculate("3 + 12 * 2") << std::endl;
//    std::cout << Solution().calculate("3 + 12 * 2 - 3 / 2") << std::endl;
//    std::cout << Solution().calculate(" 3+5 / 2 * 3 - 10/3+2") << std::endl;
    std::cout << Solution().calculate("2147483647") << std::endl;
    return 0;
}