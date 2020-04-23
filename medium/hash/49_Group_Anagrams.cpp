//
// Created by ranpeng on 2020/4/14.
//

#include "common.h"

/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (auto &s : strs) {
            string key = s;
            std::sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        vector<vector<string>> results;
        results.reserve(m.size());
        auto iter = m.begin();
        while (iter != m.end()) {
            results.push_back(iter->second);
            ++iter;
        }
        return results;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto results = Solution().groupAnagrams(strs);
    for (auto r : results) {
        printVector(r, " ");
    }
    return 0;
}