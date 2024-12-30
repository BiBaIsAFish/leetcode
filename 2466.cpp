#include <bits/stdc++.h>

using namespace std;

// 3ms, 96.09%; 11.72MB, 62.82%;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1);
        int mod = 1e9+7;
        dp[0] = 1;
        for (int i = 1; i <= high; ++i) {
            if (i - zero >= 0) {
                dp[i] += dp[i - zero];
            }
            if (i - one >= 0) {
                dp[i] += dp[i - one];
            }
            dp[i] %= mod;
        }
        
        int res = 0;
        for (int i = low; i <= high; ++i) {
            res += dp[i];
            res %= mod;
        }

        return res;
    }
};

class testCase {
public:
    int low, high, zero, one, ans;

    testCase(int low, int high, int zero, int one, int ans)
    : low{low}, high{high}, zero{zero}, one{one}, ans{ans} {};
};

int main () {
    Solution sol;
    testCase c1(3, 3, 1, 1, 8);
    testCase c2(2, 3, 1, 2, 5);
    if (sol.countGoodStrings(c1.low, c1.high, c1.zero, c1.one) == c1.ans
        && sol.countGoodStrings(c2.low, c2.high, c2.zero, c2.one) == c2.ans) {
            cout << "pass" << endl;
    } else {
        cout << "fail" << endl;
    }
}