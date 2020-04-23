//
// Created by ranpeng on 2020/4/17.
//

#include "common.h"

/*
Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k
times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat
numbers, k. For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/
class Solution {
public:
    string decodeStringV1(string str) {
        stack<string> numStack;
        stack<string> strStack;
        int i = 0;
        string decode;
        while (i < str.length()) {
            if (isdigit(str[i])) {
                string digit;
                while (str[i] != '[') {
                    digit.push_back(str[i++]);
                }
                numStack.push(digit);
                ++i; // skip '['
                string alpha;
                while (isalpha(str[i])) {
                    alpha.push_back(str[i++]);
                }
                strStack.push(alpha);
            } else if (str[i] == ']') {
                if (numStack.empty() || strStack.empty()) {
                    cout << "error string format at pos " << i << endl;
                    return "";
                }
                auto num = std::stoi(numStack.top()); numStack.pop();
                auto substr = strStack.top(); strStack.pop();
                string tmpStr;
                for (int j = 0; j < num; ++j) {
                    tmpStr.append(substr);
                }
                if (!strStack.empty()) {
                    strStack.top().append(tmpStr);
                } else {
                    decode.append(tmpStr);
                }
                ++i;
            } else if (isalpha(str[i]) ) {
                if (strStack.empty()) {
                    decode.push_back(str[i]);
                } else {
                    strStack.top().push_back(str[i]);
                }
                ++i;
            } else {
                ++i;
                cout << "error string format at pos " << i << endl;
                return ""; // error string format
            }
        }
        return decode;
    }

    string decodeString(string str) {
        stack<int> numStack;
        stack<string> strStack;
        int num = 0;
        string decode;
        for (int i = 0; i < str.size(); ++i) {
            if (isdigit(str[i])) {
                num = 10 * num + str[i] - '0';
            } if (str[i] == '[') {
                numStack.push(num);
                strStack.push(decode);
                num = 0;
                decode.clear();
            } else if (str[i] == ']') {
                int n = numStack.top(); numStack.pop();
                for (int j = 0; j < n; ++j) {
                    strStack.top().append(decode);
                }
                decode = strStack.top(); strStack.pop();
            } else if (isalpha(str[i])) {
                decode.push_back(str[i]);
            }
        }
        return strStack.empty() ? decode : strStack.top();
    }
};

int main() {
    cout << Solution().decodeString("") << endl;
    cout << Solution().decodeString("a") << endl;
    cout << Solution().decodeString("3[a]2[bc]") << endl;
    cout << Solution().decodeString("3[a2[c]]") << endl;
    cout << Solution().decodeString("2[abc]3[cd]ef") << endl;
    cout << Solution().decodeString("2[abc]xyz3[cd]ef") << endl;
    cout << Solution().decodeString("3[a2[c]xyz2[qw]]def") << endl;
}