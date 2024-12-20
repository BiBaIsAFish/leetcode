#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 0ms, 100.00%; 78.40MB, 63.72%;
class Solution {
public: 
    void dfs(TreeNode* root, unordered_map<int, vector<int>>& mp, int level) {
        if (level & 1) {
            mp[level].push_back(root->val);
        }
        if (root->left) {
            dfs(root->left, mp, level+1);
        }
        if (root->right) {
            dfs(root->right, mp, level+1);
        }
    }

    void reverse(TreeNode* root, unordered_map<int, vector<int>>& mp, int level) {
        if (level & 1) {
            root->val = mp[level].back();
            mp[level].pop_back();
        }
        if (root->left) {
            reverse(root->left, mp, level+1);
        }
        if (root->right) {
            reverse(root->right, mp, level+1);
        }
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        unordered_map<int, vector<int>> mp;
        dfs(root, mp, 0);
        reverse(root, mp, 0);

        return root;
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
                curr->left = new TreeNode(data[i++]);
                q.push(curr->left);
            }
            if (i < n) {
                curr->right = new TreeNode(data[i++]);
                q.push(curr->right);
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

int main() {
    Solution sol;
    testCase c1({2,3,5,8,13,21,34}, {2,5,3,8,13,21,34});
    testCase c2({7,13,11}, {7,11,13});
    testCase c3({0,1,2,0,0,0,0,1,1,1,1,2,2,2,2}, {0,2,1,0,0,0,0,2,2,2,2,1,1,1,1});

    if (c1.flatten(sol.reverseOddLevels(c1.root)) == c1.ans &&
            c2.flatten(sol.reverseOddLevels(c2.root)) == c2.ans &&
                c3.flatten(sol.reverseOddLevels(c3.root)) == c3.ans) {

        cout << "pass" << endl;                
    } else {
        cout << "fail" << endl;
    }
}