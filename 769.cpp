#include <bits/stdc++.h>

using namespace std;

// 0ms, 100.00%; 9.20MB, 20.72%;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int Max = -1;
        for (int i = 0; i < arr.size(); ++i) {
            Max = max(Max, arr[i]);
            if (Max == i) {
                res++;
            }
        }

        return res;
    }
};

class testCase{
public:
    vector<int> arr;
    int ans;

    testCase(vector<int> arr, int ans) : arr{arr}, ans{ans} {};
};

int main () {
    Solution sol;
    testCase c1({4,3,2,1,0}, 1);
    testCase c2({1,0,2,3,4}, 4);
    if (sol.maxChunksToSorted(c1.arr) == c1.ans && sol.maxChunksToSorted(c2.arr) == c2.ans) {
        cout << "pass" << endl;
    } else {
        cout << "fail" << endl;
    }
}