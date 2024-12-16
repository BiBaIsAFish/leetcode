#include <bits/stdc++.h>

using namespace std;

// 0ms, 100%; 27.84 MB, 20.77%

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
        }
        while (k--) {
            pq.push({pq.top().first * multiplier, pq.top().second});
            pq.pop();
        }

        while (!pq.empty()) {
            nums[pq.top().second] = pq.top().first;
            pq.pop();
        }

        return nums;
    }
};

class testCase {
public:
    vector<int> nums;
    int k;
    int multipler;
    vector<int> ans;

    testCase(vector<int> nums, int k, int multipler, vector<int> ans)
    : nums{nums}, k{k}, multipler{multipler}, ans{ans} {}
};

int main () {
    Solution sol;
    testCase case1({2,1,3,5,6}, 5, 2, {8,4,6,5,6});
    testCase case2({1,2}, 3, 4, {16,8});

    if (sol.getFinalState(case1.nums, case1.k, case1.multipler) == case1.ans && sol.getFinalState(case2.nums, case2.k, case2.multipler) == case2.ans) {
        cout << "pass" << endl;
    } else {
        cout << "fail" << endl;
    }
}