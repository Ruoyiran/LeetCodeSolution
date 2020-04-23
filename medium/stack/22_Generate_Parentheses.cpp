//
// Created by ranpeng on 2020/4/14.
//

#include "common.h"

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */
class Solution {
public:
    vector<string> generateParenthesisV1(int n) {
        std::string combine;
        vector<string> results;
        backtracking(n, 0, 0, combine, results);
        return results;
    }

    void backtracking(int n, int left, int right, std::string& combine, vector<string>& results) {
        if (left < right || left > n || right > n) {
            return;
        }
        if (left == right && left == n) {
            results.push_back(combine);
            return;
        }
        combine.push_back('(');
        backtracking(n, left + 1, right, combine, results);
        combine.pop_back();
        combine.push_back(')');
        backtracking(n, left, right + 1, combine, results);
        combine.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        stack<pair<string, pair<int, int>>> s;
        s.push({"", {0, 0}});
        vector<string> results;
        while (!s.empty()) {
            auto p = s.top(); s.pop();
            int left = p.second.first;
            int right = p.second.second;
            if (left < right || left > n || right > n) {
                continue;
            }
            if (left == right && left == n) {
                results.push_back(p.first);
                continue;
            }
            s.push({p.first+'(', {left+1, right}});
            s.push({p.first+')', {left, right+1}});
        }
        return results;
    }
};

int main() {
    Solution solution;
    auto results = solution.generateParenthesis(3);
    printVector(results, "\n");
    return 0;
}
