//
// Created by ranpeng on 2020/4/16.
//

#include "common.h"

/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a topo_graph represented by a list of edges, not adjacency matrices.
 */
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

    int topologicalSort(const vector<vector<bool>> &graph, vector<int> &inDegree, queue<int> &q) {
        int count = 0;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            ++count;
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
        return count;
    }

    /*
     * 初始化一个int[] inDegree保存每一个结点的入度。
     * 对于图中的每一个结点的子结点，将其子结点的入度加1。
     * 选取入度为0的结点开始遍历，并将该节点加入输出。
     * 对于遍历过的每个结点，更新其子结点的入度：将子结点的入度减1。
     * 重复步骤3，直到遍历完所有的结点。
     * 如果无法遍历完所有的结点，则意味着当前的图不是有向无环图。不存在拓扑排序。
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, false));
        buildGraph(numCourses, prerequisites, graph);
        vector<int> inDegree(numCourses);
        initInDegree(graph, inDegree);
        queue<int> q;
        initInDegreeQueue(inDegree, q);
        int count = topologicalSort(graph, inDegree, q);
        return count == numCourses;
    }
};

int main() {
    vector<vector<int>> nums = {
            {1, 0},
            {1, 2},
            {2, 3},
    };
    int numCourses = 4;
    cout << Solution().canFinish(numCourses, nums) << endl;
    return 0;
}