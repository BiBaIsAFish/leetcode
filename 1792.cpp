#include <bits/stdc++.h>

using namespace std;

// 284ms, 90.60%; 97.90MB, 42.11%;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> pq;
        int n = classes.size();
        for (int i = 0; i < n; ++i) {
            int pass = classes[i][0], total = classes[i][1];
            double diff = (double)(pass+1) / (total + 1) - (double)pass / total;
            pq.push({diff, i});
        }

        while (extraStudents) {
            int idx = pq.top().second;
            pq.pop();
            ++classes[idx][0], ++classes[idx][1], --extraStudents;
            int pass = classes[idx][0], total = classes[idx][1];
            double diff = (double)(pass+1) / (total + 1) - (double)pass / total;
            pq.push({diff, idx});
        }

        double res = 0;
        for (int i = 0; i < n; ++i) {
            res += (double)classes[i][0] / classes[i][1];
        }
        res /= n;

        return round(res * 1e5) / 1e5;
    }
};



int main () {
    Solution sol;
    vector<vector<int>> case1_classes{{1,2},{3,5},{2,2}};
    vector<vector<int>> case2_classes{{2,4},{3,9},{4,5},{2,10}};
    int case1_extraStudents = 2, case2_extraStudents = 4;
    if (sol.maxAverageRatio(case1_classes, case1_extraStudents) == 0.78333 && sol.maxAverageRatio(case2_classes, case2_extraStudents) == 0.53485) {
        cout << "pass" << endl;
    } else {
        cout << "fail" << endl;
    }
}