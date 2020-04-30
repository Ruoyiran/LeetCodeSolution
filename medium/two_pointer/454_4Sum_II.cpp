//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

class Solution {
public:
    int fourSumCountV1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                ++m[A[i] + B[j]];
            }
        }
        int res = 0;
        for (int i = 0; i < C.size(); ++i) {
            for (int j = 0; j < D.size(); ++j) {
                int target = -(C[i] + D[j]);
                if (m.find(target) != m.end()) {
                    res += m[target];
                }
            }
        }
        return res;
    }

    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m1, m2;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                ++m1[A[i] + B[j]];
                ++m2[-(C[i] + D[j])];
            }
        }
        int  res = 0;
        for(auto& p : m1) {
            if (m2.find(-p.first) != m2.end()) {
                res += p.second * m2[-p.first];
            }
        }
        return res;
    }
};

int main() {
    vector<int> A = { 1, 2};
    vector<int> B = {-2,-1};
    vector<int> C = {-1, 2};
    vector<int> D = { 0, 2};
    std::cout << Solution().fourSumCount(A, B, C, D) << std::endl;
    return 0;
}