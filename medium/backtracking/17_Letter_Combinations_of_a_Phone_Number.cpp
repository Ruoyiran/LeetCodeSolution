//
// Created by ranpeng on 2020/4/13.
//
#include "common.h"

/*
Given a string containing digits from 2-9inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        map<char, string> letters = {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"},
        };
        string combination;
        vector<string> results;
        backtracking(combination, digits, letters, results);
        return results;
    }

    void backtracking(string &combination, const string& nextDigits, const map<char, string> &lettersMap, vector<string> &results) {
        if (nextDigits.empty()) {
            results.push_back(combination);
            return;
        }
        char digit = nextDigits[0];
        string letters = lettersMap.find(digit)->second;
        for (char letter : letters) {
            combination.push_back(letter);
            backtracking(combination, nextDigits.substr(1), lettersMap, results);
            combination.pop_back();
        }
    }
};

int main() {
    Solution solution;
    string s = "2345";
    auto results = solution.letterCombinations(s);
    printVector(results, " ");
    return 0;
}