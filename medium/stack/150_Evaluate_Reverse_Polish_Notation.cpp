//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be
any divide by zero operation.
Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation:
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, std::function<int(int,int)>> operators = {
                {"+", std::plus<int>()},
                {"-", std::minus<int>()},
                {"*", std::multiplies<int>()},
                {"/", std::divides<int>()}
        };
        stack<int> nums;
        for(auto& s : tokens) {
            if (operators.find(s) != operators.end()) {
                if (nums.size() < 2) {
                    return 0;
                }
                auto a = nums.top(); nums.pop();
                auto b = nums.top(); nums.pop();
                nums.push(operators[s](b, a));
            } else {
                nums.push(std::stoi(s));
            }
        }
        return nums.empty() ? 0 : nums.top();
    }
};

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    std::cout << Solution().evalRPN(tokens) << std::endl;
    tokens = {"4", "13", "5", "/", "+"};
    std::cout << Solution().evalRPN(tokens) << std::endl;
    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::cout << Solution().evalRPN(tokens) << std::endl;
    tokens = {"10"};
    std::cout << Solution().evalRPN(tokens) << std::endl;
    return 0;
}