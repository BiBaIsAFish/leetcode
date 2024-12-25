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

// 0ms, 100.00%; 22.57MB, 41.18%;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int curr = INT_MIN;
            for (int i = 0; i < n; ++i) {
                TreeNode* front = q.front();
                q.pop();
                curr = max(curr, front->val);
                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            res.push_back(curr);
        }

        return res;
    }
};

class testCase {
public:
    vector<int> data;
    vector<int> ans;
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

    vector<int> flatten(TreeNode* root) {
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

    testCase(vector<int> data, vector<int>ans) : data{data}, ans{ans} {
        root = create();
    };
};

int main () {
    Solution sol;
    testCase c1({1,3,2,5,3,-1,9}, {1,3,9});
    testCase c2({1,2,3}, {1,3});

    if (sol.largestValues(c1.root) == c1.ans && sol.largestValues(c2.root) == c2.ans) {
        cout << "pass" << endl;
    } else {
        cout << "fail" << endl;
    }
}