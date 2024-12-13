// 透過 pq 取 nums 中的最小值，並用 pair 儲存原始 index，以利後面進行 mark
// 下次考慮使用 vector 儲存，畢竟只需要 sort 過一次就好。
// 116 ms, 71.84% ; 108.78 MB, 33.33%

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long int res = 0;
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
        }
        vector<int> marked(n, false);
        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            if (marked[top.second]) {
                continue;
            }
            res += top.first;
            if (top.second + 1 < n) {
                marked[top.second+1] = true;
            }
            if (top.second - 1 >= 0) {
                marked[top.second-1] = true;
            }
            // cout << top.first << " " << top.second << endl;
        }



        return res;
    }
};

int main () {
    Solution sol;
    vector<int> testcase1{2,1,3,4,5,2}, testcase2{2,3,5,1,3,2};
    int res1{7}, res2{5};
    if (sol.findScore(testcase1) == res1 && sol.findScore(testcase2) == res2) {
        cout << "pass" << endl;
    }
}