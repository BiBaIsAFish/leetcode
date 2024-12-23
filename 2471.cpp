#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 893ms, 12.02%; 178.54MB, 78.00%

class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> nums;
            for (int i = 0; i < n; ++i) {
                TreeNode* curr = q.front();
                q.pop();
                nums.push_back(curr->val);
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }

            vector<int> sorted = nums;
            sort(begin(nums), end(nums));
            int nn = nums.size();
            for (int i = 0; i < nn; ++i) {
                int a = nums[i], b = sorted[i];
                if (a != b) {
                    auto it = find(begin(nums), end(nums), b);
                    int idx = distance(begin(nums), it);
                    swap(nums[i], nums[idx]);
                    res++;
                }
            }
        }

        return res;
    }
};

class testCase {
public:
    vector<int> data;
    int ans;
    TreeNode* root;

    TreeNode* create() {
        TreeNode* root = new TreeNode(data[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1, n = data.size();
        while (!q.empty() && i < n) {
            TreeNode* curr = q.front();
            q.pop();

            if (i < n) {
                if (data[i] != -1) {
                    curr->left = new TreeNode(data[i]);
                    q.push(curr->left);
                }
                i++;
            }
            if (i < n) {
                if (data[i] != -1) {
                    curr->right = new TreeNode(data[i]);
                    q.push(curr->right);
                }
                i++;
            }
        }

        return root;
    }

    vector<int> flatten() {
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            res.push_back(curr->val);
            if (curr->left) {
                q.push(curr->left);
            }            
            if (curr->right) {
                q.push(curr->right);
            }
        }

        return res;
    }

    testCase(vector<int> data, int ans) : data{data}, ans{ans} {
        root = create();
    };
};

int main () {
    Solution sol;
    testCase c1({1,4,3,7,6,8,5,-1,-1,-1,-1,9,-1,10}, 3);
    testCase c2({1,3,2,7,6,5,4}, 3);
    testCase c3({1,2,3,4,5,6}, 0);

    if (sol.minimumOperations(c1.root) == c1.ans
        &&  sol.minimumOperations(c2.root) == c2.ans
        &&  sol.minimumOperations(c3.root) == c3.ans) {
        cout << "pass" << endl;
    } else {
        cout << "fail" << endl;
    }
}