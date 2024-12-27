#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 0ms, 100.00%; 47.29MB, 28.33%;
    // int maxScoreSightseeingPair(vector<int>& values) {
    //     int n = values.size();
    //     vector<int> dp(n);
    //     dp[0] = values[0];
    //     int res = 0;
    //     for (int i = 1; i < n; ++i) {
    //         int curr = values[i];
    //         res = max(curr + dp[i-1] - 1, res);
    //         dp[i] = max(curr, dp[i-1] - 1);
    //     }

    //     return res;
    // }

    // one integer is sufficient;
    // 0ms, 100.00%; 45.50MB, 65.45%;
    int maxScoreSightseeingPair(vector<int>& values) {
        int dp = values[0];
        int res = 0;
        for (int i = 1; i < values.size(); ++i) {
            int curr = values[i];
            res = max(curr + dp - 1, res);
            dp = max(dp-1, curr);
        }

        return res;
    }
};

class testCase {
public:
    vector<int> values;
    int ans;

    testCase(vector<int> values, int ans)
    : values{values}, ans{ans} {};
};

int main () {
    Solution sol;
    testCase c1({8,1,5,2,6}, 11);
    testCase c2({1,2}, 2);

    if (sol.maxScoreSightseeingPair(c1.values) == c1.ans && sol.maxScoreSightseeingPair(c2.values) == c2.ans) {
        cout << "pass" << endl;
    } else {
        cout << "fail" << endl;
    }
}