//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), start = 0, res = 0;
        int m[128] = {0};
        bool ok = true;
        for (char c : s) ++m[c];
        for (int i = 0; i < n; ++i) {
            if (m[s[i]] < k) {
                res = max(res, longestSubstring(s.substr(start, i - start), k));
                ok = false;
                start = i + 1;
            }
        }
        return ok ? n : max(res, longestSubstring(s.substr(start, n - start), k));
    }
};

int main() {
    std::cout << Solution().longestSubstring("aaabb", 3) << std::endl;
    std::cout << Solution().longestSubstring("ababbc", 2) << std::endl;
    std::cout << Solution().longestSubstring("ababacb", 3) << std::endl;
    return 0;
}