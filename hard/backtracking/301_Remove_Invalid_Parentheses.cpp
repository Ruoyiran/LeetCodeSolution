//
// Created by ranpeng on 2020/4/19.
//

#include "common.h"

/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Example 1:

Input: "()())()"
Output: ["()()()", "(())()"]
Example 2:

Input: "(a)())()"
Output: ["(a)()()", "(a())()"]
Example 3:

Input: ")("
Output: [""]
*/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        dfs(s, 0, 0, res, {'(', ')'});
        return res;
    }

private:
    void dfs(string &s, const int pos, const int last, vector<string> &res, pair<char, char> par) {
        for (int i = 0, count = 0; i < s.size(); ++i) {
            if (s[i] == par.first) --count;
            else if (s[i] == par.second) ++count;
            if (count <= 0) continue;
            for (int j = last; j <= i; ++j) {
                if (s[j] == par.second && (j == last || s[j - 1] != par.second)) {
                    // 当有连续的par[1]时，删任何一个结果都是一样的，所以跳过。
                    string ns = s.substr(0, j) + s.substr(j + 1);
                    dfs(ns, i, j, res, par);
                }
            }
            return;
        }
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        if (par.first == '(') dfs(reversed, 0, 0, res, {')', '('});
        else res.push_back(reversed);
    }
};

int main() {
    string s = "()())()";
    auto res = Solution().removeInvalidParentheses(s);
    printVector(res, " ");
    return 0;
}