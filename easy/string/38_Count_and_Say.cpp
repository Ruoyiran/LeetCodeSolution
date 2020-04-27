//
// Created by ranpeng on 2020/4/27.
//

#include "common.h"

/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively,
in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Explanation: This is the base case.
Example 2:

Input: 4
Output: "1211"
Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means
frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which
is "1211".
*/
class Solution {
public:
    string countAndSayV1(int n) {
        if (n < 1) {
            return "";
        }
        string res = "1";
        for (int i = 1; i < n; ++i) {
            res = getNextString(res);
            std::cout << res << std::endl;
        }
        return res;
    }

    string countAndSay(int n) {
        if (n < 1) {
            return "";
        }
        if (n == 1) {
            return "1";
        }
        string res = countAndSay(n-1);
        int    count = 1;
        string s;
        for (int i = 0; i < res.length()-1; ++i) {
            if (res[i] == res[i+1]) {
                ++count;
            } else {
                s.push_back('0'+count);
                s.push_back(res[i]);
                count = 1;
            }
        }
        if (count > 0) {
            s.push_back('0'+count);
            s.push_back('1');
        }
        return s;
    }

    string getNextString(const string& str) {
        char prev = '0';
        int count = 0;
        string res;
        for(auto c : str) {
            if (prev == c) {
                ++count;
            } else {
                if (count > 0) {
                    res.push_back('0' + count);
                    res.push_back(prev);
                }
                count = 1;
            }
            prev = c;
        }
        if (count > 0) {
            res.push_back('0' + count);
            res.push_back(prev);
        }
        return res;
    }
};

int main() {
    std::cout << Solution().countAndSay(4) << std::endl;
    return 0;
}