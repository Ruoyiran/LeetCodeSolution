//
// Created by ranpeng on 2020/4/29.
//

#include "common.h"

class Solution {
public:
    void buildGraph(int n, const vector<vector<int>>& vertexes, vector<vector<bool>> &graph) {
        for (int i = 0; i < vertexes.size(); ++i) {
            for (int j = 1; j < vertexes[i].size(); ++j) {
                int x = vertexes[i][j-1];
                int y = vertexes[i][j];
                graph[x][y] = true;
            }
        }
    }

    void initInDegree(const vector<vector<bool>>& graph, vector<int> &inDegree) {
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                if (graph[i][j]) {
                    ++inDegree[j];
                }
            }
        }
    }

    void initInDegreeQueue(const vector<int> &inDegree, queue<int> &q) {
        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
    }

    vector<int> topologicalSort(const vector<vector<bool>> &graph, vector<int> &inDegree, queue<int> &q) {
        vector<int> res;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            res.push_back(i);
            for (int j = 0; j < inDegree.size(); ++j) {
                if (!graph[i][j]) {
                    continue;
                }
                --inDegree[j];
                if (inDegree[j] == 0) {
                    q.push(j);
                }
            }
        }
        return res;
    }

    /*
     * 初始化一个int[] inDegree保存每一个结点的入度。
     * 对于图中的每一个结点的子结点，将其子结点的入度加1。
     * 选取入度为0的结点开始遍历，并将该节点加入输出。
     * 对于遍历过的每个结点，更新其子结点的入度：将子结点的入度减1。
     * 重复步骤3，直到遍历完所有的结点。
     * 如果无法遍历完所有的结点，则意味着当前的图不是有向无环图。不存在拓扑排序。
     */
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
        buildGraph(numCourses, prerequisites, graph);
        vector<int> inDegree(numCourses);
        initInDegree(graph, inDegree);
        queue<int> q;
        initInDegreeQueue(inDegree, q);
        auto res = topologicalSort(graph, inDegree, q);
        if (res.size() != numCourses) {
            return {};
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    auto res = Solution().findOrder(4, prerequisites);
    printVector(res);
    return 0;
}
