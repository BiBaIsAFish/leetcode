#include <bits/stdc++.h>

using namespace std;

// 1333ms, 9.04%; 452.04MB, 6.54%;

class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& g, set<int>& visited, int curr, int depth, int& res) {
        visited.insert(curr);
        for (auto& node : g[curr]) {
            if (!visited.count(node)) {
                dfs(g, visited, node, depth+1, res);
            }
        }

        res = max(depth, res);
    }

    int bfs(unordered_map<int, vector<int>>& g) {
        queue<int> q;
        q.push(0);
        set<int> visited;
        int res;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res = curr;
            visited.insert(curr);
            for (auto& node : g[curr]) {
                if (!visited.count(node)) {
                    q.push(node);
                }
            }
        }

        return res;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> g1, g2;
        for (auto& e : edges1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);
        }
        
        int n1 = bfs(g1), n2 = bfs(g2);
        set<int> visited;
        int l1 = -1, l2 = -1;
        dfs(g1, visited, n1, 0, l1);
        visited.clear();
        dfs(g2, visited, n2, 0, l2);

        int res = max(l1, l2);
        res = max(res, (l1 + 1) / 2 + (l2 + 1) / 2 + 1);
        // printf("n1: %d, n2: %d, l1: %d, l2: %d\n", n1, n2, l1, l2);


        return res;
    }
};

class testCase {
public:
    vector<vector<int>> edges1;
    vector<vector<int>> edges2;
    int ans;

    testCase(vector<vector<int>> edges1, vector<vector<int>> edges2, int ans)
    : edges1{edges1}, edges2{edges2}, ans{ans} {};
};

int main () {
    Solution sol;
    testCase c1({{0,1},{0,2},{0,3}}, {{0,1}}, 3);
    testCase c2({{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}}, {{0,1},{0,2},{0,3},{2,4},{2,5},{3,6},{2,7}}, 5);
    if (sol.minimumDiameterAfterMerge(c1.edges1, c1.edges2) == c1.ans && sol.minimumDiameterAfterMerge(c2.edges1, c2.edges2) == c2.ans) {
        cout << "pass" << endl;
    } else {
        cout << "fail" << endl;
    }
}