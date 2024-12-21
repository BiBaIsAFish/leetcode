#include <bits/stdc++.h>

using namespace std;

// 95ms, 89.87%; 174.35MB, 75.95%

class Solution {
public:
    void dfs(vector<vector<int>>& g, int curr, int parent, vector<int>& values, int k, int& res, vector<bool>& visited) {
        visited[curr] = true;
        for (auto& node : g[curr]) {
            if (!visited[node]) {
                dfs(g, node, curr, values, k, res, visited);
            }
        }
        if (values[curr] % k == 0) {
            res++;
        } else {
            values[parent] = (values[parent] + values[curr]) % k;
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; ++i) {
            values[i] %= k;
        }
        int res = 0;
        vector<bool> visited(n, false);
        dfs(g, 0, -1, values, k, res, visited);

        return res;
    }
};

class testCase{
public:
    int n;
    vector<vector<int>> edges;
    vector<int> values;
    int k;
    int ans;

    testCase(int n, vector<vector<int>> edges, vector<int> values, int k, int ans)
    : n{n}, edges{edges}, values{values}, k{k}, ans{ans} {};
};

int main () {
    Solution sol;
    testCase c1(5, {{0,2},{1,2},{1,3},{2,4}}, {1,8,1,4,4}, 6, 2);
    testCase c2(7, {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}}, {3,0,6,1,5,2,1}, 3, 3);

    if (sol.maxKDivisibleComponents(c1.n, c1.edges, c1.values, c1.k) == c1.ans
        && sol.maxKDivisibleComponents(c2.n, c2.edges, c2.values, c2.k) == c2.ans) {
        cout << "pass" << endl;
    } else {
        cout << "fail" << endl;
    }
}