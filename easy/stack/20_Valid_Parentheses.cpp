//
// Created by ranpeng on 2020/4/12.
//
#include "common.h"

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
 */
class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) {
            return false;
        }
        stack<char> v;
        for(char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                v.push(c);
            } else {
                if (v.empty()) {
                    return false;
                }
                char t = v.top();
                v.pop();
                if (t == '(' && c != ')') {
                    return false;
                }
                if (t == '{' && c != '}') {
                    return false;
                }
                if (t == '[' && c != ']') {
                    return false;
                }
            }
        }
        return v.empty();
    }
};

int main() {
    Solution solution;
    string s1 = "()[]{}";
    string s2 = "()";
    string s3 = "(]";
    string s4 = "([)]";
    string s5 = "([]{})";
    string s6 = "((";
    string s7 = ")(";
    cout << s1 << ": " << solution.isValid(s1) << endl;
    cout << s2 << ": " << solution.isValid(s2) << endl;
    cout << s3 << ": " << solution.isValid(s3) << endl;
    cout << s4 << ": " << solution.isValid(s4) << endl;
    cout << s5 << ": " << solution.isValid(s5) << endl;
    cout << s6 << ": " << solution.isValid(s6) << endl;
    cout << s7 << ": " << solution.isValid(s7) << endl;
}
