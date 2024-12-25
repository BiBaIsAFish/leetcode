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