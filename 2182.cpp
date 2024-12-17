#include <bits/stdc++.h>

using namespace std;

// 60ms, 33.16%; 28.14MB, 32.11%

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> mp;
        for (auto& c : s) {
            mp[c]++;
        }
        priority_queue<pair<char, int>> pq;
        for (auto& it : mp) {
            pq.push({it.first, it.second});
        }
        string res = "";

        // while (!pq.empty()) {
        //     auto top = pq.top();
        //     pq.pop();
        //     cout << top.first << " " << top.second << endl;
        // }

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            // cout << "top: " << top.first << " " << top.second << endl;
            for (int i = 0; top.second && i < repeatLimit; ++i) {
                res += top.first;
                top.second--;
            }
            if (top.second && !pq.empty()) {
                auto mid = pq.top();
                pq.pop();
                res += mid.first;
                mid.second--;
                // cout << res << endl;
                if (mid.second) {
                    // cout << "mid: " << mid.first << " " << mid.second << endl;
                    pq.push(mid);
                }
                pq.push(top);
            }
        }
        
        return res;
    }
};

class testCase {
public:
    string s;
    int repeatLimit;
    string ans;

    testCase(string s, int repeatLimit, string ans)
    : s{s}, repeatLimit{repeatLimit}, ans{ans} {}
};

int main () {
    Solution sol;
    testCase c1("cczazcc", 3, "zzcccac");
    testCase c2("aababab", 2, "bbabaa");

    if (sol.repeatLimitedString(c1.s, c1.repeatLimit) == c1.ans && sol.repeatLimitedString(c2.s, c2.repeatLimit) == c2.ans) {
        cout << "pass" << endl;
    } else {
        cout << "fail" << endl;
    }
}