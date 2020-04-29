//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
class Solution {
public:
    // BFS
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> curr;
        curr.push({beginWord, 1});
        unordered_set<string> wordDict(wordList.begin(), wordList.end()), visits;
        visits.insert(beginWord);
        int level = 1;
        while (!curr.empty()) {
            auto p = curr.front(); curr.pop(); // 不能取引用，MacOS上OK，LeetCode运行时错误
            auto& s = p.first;
            for (int i = 0; i < s.length(); ++i) {
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == s[i]) {
                        continue;
                    }
                    auto t = s;
                    t[i] = c;
                    if (wordDict.find(t) == wordDict.end()) {
                        continue;
                    }
                    if (t == endWord) {
                        return p.second + 1;
                    }
                    if (visits.find(t) == visits.end()) {
                        curr.push({t, p.second+1});
                        visits.insert(t);
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    std::cout << Solution().ladderLength(beginWord, endWord, wordList) << std::endl;


    beginWord = "hit";
    endWord = "cog";
    wordList = {"hot","dot","dog","lot","log"};
    std::cout << Solution().ladderLength(beginWord, endWord, wordList) << std::endl;

    beginWord = "qa";
    endWord = "sq";
    wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    std::cout << Solution().ladderLength(beginWord, endWord, wordList) << std::endl;
}