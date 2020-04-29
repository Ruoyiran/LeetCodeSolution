//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5"
Example 2:

Input: numerator = 2, denominator = 1
Output: "2"
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        /*
        1. 分子为0，返回“0”。
        2. 分母为0，返回空字符串。
        3. 可以整除，这样就可以直接转换成字符串。
        4. 不可以整除：
            4.1: 循环将余数保存，当余数重复出现时，是循环小数，在余数第一次出现的位置插入'('，最后位置插入')'。
            4.2: 余数为0，小数点后不是循环小数，可以直接转换成字符串。
         */
        if (numerator == 0) { // 分子为0
            return "0";
        }
        if (denominator == 0) { // 分母为零
            return "";
        }
        string decimal;

        long long num = numerator;
        long long den = denominator;
        int sign = ((num < 0) ^ (den < 0)) ? -1 : 1;
        num = abs(num);
        den = abs(den);
        if (num % den == 0) {
            decimal = std::to_string(num/den);
        } else {
            decimal = std::to_string(num/den) + ".";
        }
        long long rest = num % den;
        unordered_map<long long, int> restPos;
        int index = decimal.length();
        while (rest != 0 && restPos.find(rest) == restPos.end()) {
            restPos[rest] = index++;
            rest *= 10;
            decimal += std::to_string(rest/den);
            rest %= den;
        }
        if (rest != 0) { // is infinity loop
            decimal.insert(restPos[rest], 1, '(');
            decimal += ")";
        }
        if (sign < 0) {
            return "-" + decimal;
        }
        return decimal;
    }
};

int main() {
    std::cout << Solution().fractionToDecimal(1, 3) << std::endl;
    std::cout << Solution().fractionToDecimal(2, 1) << std::endl;
    std::cout << Solution().fractionToDecimal(-2, 1) << std::endl;
    std::cout << Solution().fractionToDecimal(-2, 3) << std::endl;
    std::cout << Solution().fractionToDecimal(-2, 3) << std::endl;
    std::cout << Solution().fractionToDecimal(-1, INT32_MIN) << std::endl;
    std::cout << Solution().fractionToDecimal(7, -12) << std::endl;
    return 0;
}