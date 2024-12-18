#include <bits/stdc++.h>

using namespace std;

// 0ms, 100.00%; 14.33MB, 9.86%

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int, int>> st;
        int n = prices.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && st.top().first >= prices[i]) {
                auto it = st.top();
                st.pop();
                res[it.second] = it.first - prices[i];

            }
            st.push({prices[i], i});
        }

        while (!st.empty()) {
            auto it = st.top();
            st.pop();
            res[it.second] = it.first;
        }

        return res;
    }
};

class testCase{
public:
    vector<int> prices;
    vector<int> ans;

    testCase(vector<int> prices, vector<int> ans) : prices{prices}, ans{ans} {}
};

int main () {
    testCase c1({8,4,6,2,3}, {4,2,4,2,3});
    testCase c2({1,2,3,4,5}, {1,2,3,4,5});
    testCase c3({10,1,1,6}, {9,0,1,6});
    Solution sol;

    if (sol.finalPrices(c1.prices) == c1.ans && sol.finalPrices(c2.prices) == c2.ans && sol.finalPrices(c3.prices) == c3.ans) {
        cout << "pass" << endl;
    } else {
        cout << "fail" << endl;
    }
}
