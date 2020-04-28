//
// Created by ranpeng on 2020/4/27.
//

#include "common.h"
/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and
Java's indexOf().
*/
// Reference:
// https://www.jianshu.com/p/dcfa55a773f0
// https://blog.csdn.net/u010232171/article/details/41945605
class Solution {
public:
    int strStrV1(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int len1 = static_cast<int>(haystack.length());
        int len2 = static_cast<int>(needle.length());
        for (int i = 0; i < len1-len2+1; ++i) {
            int k = i;
            int j = 0;
            while (k < haystack.length() && j < needle.length()) {
                if (haystack[k] != needle[j]) {
                    break;
                }
                ++k;
                ++j;
            }
            if (j == needle.length()) {
                return i;
            }
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        vector<int> next;
        genNext(needle, next);
        int k = 0;
        int i = 0;
        while (i < haystack.length() && k < needle.length()) {
            if (haystack[i] == needle[k]) {
                ++i;
                ++k;
            } else {
                if (k > 0) {
                    // 不匹配时，前面k个字符是匹配的。移动位数 = 已匹配的字符数(k) - 对应的部分匹配值(next[k-1])
                    // 更新k = k - 移动位数
                    k = next[k-1];
                } else {
                    ++i;
                }
            }
        }
        if (k == needle.length()) {
            return i - k;
        }
        return -1;
    }

    /*
    计算next数组
    前缀和后缀公共部分的最大长度
    一个字符串ababa，他的前缀是可以是a,ab,aba,abab(不包含最后一位)，后缀是a,ba,aba,baba(不包含第一位)
    前缀后缀公共部分就是a和aba，公共部分最大就是aba，公共部分的最大长度就是3

    next数组
    next数组是ptr每一位及之前的字符串中，前缀和后缀公共部分的最大长度的集合
    比如ptr字符串的长度是11(abxabwabxad)，那么next数组就有11个元素

    next[0]表示ptr前一位a中，前缀和后缀公共部分的最大长度，由于a中没有前缀和后缀，所以next[0]=0
    next[1]表示ptr前两位ab中，前缀和后缀公共部分的最大长度，ab的前缀是a，后缀是b，没有公共部分，所以next[1]=0
    同理
    next[2]=0(abx中无公共前后缀)
    next[3]=1(abxa公共前后缀最长为a，长度为1)
    next[4]=2(abxab公共前后缀最长为ab，长度为2)
    next[5]=0(abxabw中无公共前后缀)
    next[6]=1(abxabwa公共前后缀最长为a，长度为1)
    next[7]=2(abxabwab公共前后缀最长为ab，长度为2)
    next[8]=3(abxabwabx公共前后缀最长为abx，长度为3)
    next[9]=4(abxabwabxa公共前后缀最长为abxa，长度为4)
    next[10]=0(abxabwabxad中无公共前后缀)
    */
    void genNext(const std::string& needle, vector<int>& next) {
        next.clear();
        next.resize(needle.length());
        int k = 0;
        for (int i = 1; i < needle.length(); ++i) {
            while (k > 0 && needle[i] != needle[k]) {
                k = next[k-1];
            }
            if (needle[i] == needle[k]) {
                ++k;
            }
            next[i] = k;
        }
    }
};

int main() {
    std::string haystack = "hello";
    std::string needle = "ll";
    int i = Solution().strStr(haystack, needle);
    std::cout << i << std::endl;
    if (i != -1) {
        std::cout << haystack.substr(i, needle.length()) << std::endl;
    }

    std::cout << Solution().strStr("abb", "abaaa") << std::endl;
    return 0;
}