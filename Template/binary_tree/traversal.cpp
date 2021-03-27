#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

auto inorder_recursive(TreeNode *root, vector<int> &res) -> void {
    if (root == nullptr) return;
    inorder_recursive(root->left, res);
    res.push_back(root->val);
    inorder_recursive(root->right, res);
}

auto preorder_recursive(TreeNode *root, vector<int> &res) -> void {
    if (root == nullptr) return;
    res.push_back(root->val);
    preorder_recursive(root->left, res);
    preorder_recursive(root->right, res);
}

auto postorder_recursive(TreeNode *root, vector<int> &res) -> void {
    if (root == nullptr) return;
    postorder_recursive(root->left, res);
    postorder_recursive(root->right, res);
    res.push_back(root->val);
}

auto inorder_iterative(TreeNode *root, vector<int> &res) -> void {
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    while (!stk.empty() || cur != nullptr) {
        while (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        res.push_back(cur->val);
        stk.pop();
        cur = cur->right;
    }
}

auto preorder_iterative(TreeNode *root, vector<int> &res) -> void {
    stack<TreeNode *> stk;
    TreeNode *cur = root;
    while (!stk.empty() || cur != nullptr) {
        if (cur != nullptr) {
            res.push_back(cur->val);
            stk.push(cur->right);
            cur = cur->left;
        } else {
            cur = stk.top();
            stk.pop();
        }
    }
}

auto postorder_iterative(TreeNode *root, vector<int> &res) -> void {
    stack<TreeNode *> stk;
    TreeNode *pre = nullptr;
    TreeNode *cur = root;
    while (!stk.empty() || cur != nullptr) {
        while (cur != nullptr) {
            stk.push(cur);
            cur = cur->left;
        }
        cur = stk.top();
        if (cur->right != nullptr || cur->right == pre) {
            res.push_back(cur->val);
            stk.pop();
            pre = cur;
            cur = nullptr;
        } else {
            cur = cur->right;
        }
    }
}

auto level_order_iterative(TreeNode *root, vector<vector<int>> &res) -> void {
    if (root == nullptr) return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> level;
        int cnt = q.size();
        while (cnt > 0) {
            auto cur = q.front();
            cnt--;
            q.pop();
            level.push_back(cur->val);

            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
        }
        res.push_back(level);
    }
}