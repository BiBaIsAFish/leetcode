#include <bits/stdc++.h>

using namespace std;

// 262ms, 38.99%; 11.47MB, 79.58%;
// TODO: using dp next time;

class Solution {
public:
    int res;
    int n;

    // 在這裡問題變成有幾種數字和為 dif
    void backtracking(vector<int>& nums, int idx, int dif, int curr) {
        if (idx >= n) {
            return;
        }
        // 第 idx 個不拿
        backtracking(nums, idx+1, dif, curr);
        curr += nums[idx];
        if (curr > dif) {
            return;
        }
        // 和為 dif, res++; 但後面可能有 0
        if (curr == dif) {
            res++;
        }
        backtracking(nums, idx+1, dif, curr);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        int sum = accumulate(begin(nums), end(nums), 0);
        // 計算 sum 與 target 的差，因符號變換會導致 2 * num 的差
        // 故先排除餘 1 的情況，並除二計算出要符合的數字
        int dif = sum - target;
        if (abs(dif) & 1) {
            return 0;
        }
        dif /= 2;

        res = 0;
        // 如果 sum 與 target 相同，代表全+符合
        // 但還需進一步計算 0 所造成的重複項
        if (!dif) {
            res++;
        }
        backtracking(nums, 0, dif, 0);

        return res;
    }
};

class testCase {
public:
    vector<int> nums;
    int target;
    int ans;

    testCase(vector<int> nums, int target, int ans)
    : nums{nums}, target{target}, ans{ans} {};
};

int main () {
    Solution sol;
    testCase c1({1,1,1,1,1}, 3, 5);
    testCase c2({0, 1}, 1, 2);

    if (sol.findTargetSumWays(c1.nums, c1.target) == c1.ans && sol.findTargetSumWays(c2.nums, c2.target) == c2.ans) {
        cout << "pass" << endl;
    } else {
        cout << "fail" << endl;
    }
}