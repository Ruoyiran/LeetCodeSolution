//
// Created by ranpeng on 2020/4/28.
//

#include "common.h"

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        /*
         dp[i]表示前i个字符可以编码的情况总数，dp[0]=1，如果当前第i位能与i-1位组合成一个10~26的数字，则dp[i]=dp[i-1]+dp[i-2]，
         否则dp[i]=dp[i-1]，注意两个特殊点：如果当前位为0，则只能和前面组合，如果不能组合，则无法解密如果第一位就为0，直接返回0即可
         */
        vector<int> dp(s.length()+1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= s.length(); ++i) {
            dp[i] = s[i-1] == '0' ? 0 : dp[i-1];
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')) {
                dp[i] += dp[i-2];
            }
        }
        return dp[s.length()];
    }
};

int main() {
    std::cout << Solution().numDecodings("12") << std::endl;
    std::cout << Solution().numDecodings("226") << std::endl;
    return 0;
}