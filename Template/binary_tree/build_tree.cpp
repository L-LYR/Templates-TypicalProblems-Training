#include <functional>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

auto rebuild_from_preorder_inorder_with_stack(const vector<int> preorder,
                                              const vector<int> inorder) -> TreeNode * {
    if (inorder.empty() || preorder.empty()) return nullptr;

    int idx = 0;
    TreeNode *root = new TreeNode(preorder[0]);
    TreeNode *cur;

    stack<TreeNode *> stk;
    stk.push(root);
    for (int i = 1; i < preorder.size(); ++i) {
        cur = stk.top();
        if (cur->val != inorder[idx]) {  // left sub-tree
            cur->left = new TreeNode(preorder[i]);
            stk.push(cur->left);
        } else {
            // pop the left nodes
            while (!stk.empty() && stk.top()->val == inorder[idx]) {
                cur = stk.top();
                stk.pop();
                idx++;
            }
            // right sub-tree
            cur->right = new TreeNode(preorder[i]);
            stk.push(cur->right);
        }
    }

    return root;
}

auto rebuild_from_inorder_postorder_with_stack(const vector<int> &inorder,
                                               const vector<int> &postorder) -> TreeNode * {
    if (inorder.empty() || postorder.empty()) return nullptr;
    TreeNode *root = new TreeNode(postorder.back());
    TreeNode *cur;
    stack<TreeNode *> stk;
    stk.push(root);
    int idx = inorder.size() - 1;
    for (int i = postorder.size() - 2; i >= 0; --i) {
        cur = stk.top();
        if (cur->val != inorder[idx]) {
            cur->right = new TreeNode(postorder[i]);
            stk.push(cur->right);
        } else {
            while (!stk.empty() && stk.top()->val == inorder[idx]) {
                idx--;
                cur = stk.top();
                stk.pop();
            }
            cur->left = new TreeNode(postorder[i]);
            stk.push(cur->left);
        }
    }
    return root;
}

auto rebuild_from_preorder_postorder_with_stack(const vector<int> &preorder,
                                                const vector<int> &postorder) -> TreeNode * {
    if (preorder.empty() || postorder.empty()) return NULL;

    unordered_map<int, int> m;
    for (auto i = 0; i < postorder.size(); ++i) {
        m[postorder[i]] = i;
    }

    TreeNode *root = new TreeNode(preorder[0]);
    TreeNode *cur;
    stack<TreeNode *> stk;
    stk.push(root);
    for (int i = 1; i < preorder.size(); ++i) {
        cur = stk.top();
        while (m[cur->val] < m[preorder[i]] || (cur->left && cur->right)) {
            stk.pop();
            cur = stk.top();
        }
        if (cur->left == NULL) {
            cur->left = new TreeNode(preorder[i]);
            stk.push(cur->left);
        } else if (cur->right == NULL) {
            cur->right = new TreeNode(preorder[i]);
            stk.push(cur->right);
        }
    }
    return root;
}

auto rebuild_from_preorder_postorder_recursive(const vector<int> &preorder,
                                               const vector<int> &postorder) -> TreeNode * {
    function<TreeNode *(int, int, int, int)> rebuild;
    rebuild = [&](int preorder_lo, int preorder_hi, int postorder_lo,
                  int postorder_hi) -> TreeNode * {
        if (preorder_lo > preorder_hi || postorder_lo > postorder_hi) return nullptr;
        TreeNode *cur = new TreeNode(preorder[preorder_lo]);
        if (preorder_lo == preorder_hi) return cur;

        int i = postorder_lo;
        while (postorder[i] != preorder[preorder_lo + 1]) i++;
        int len = i - postorder_lo + 1;

        cur->left = rebuild(preorder_lo + 1, preorder_lo + len, postorder_lo, i);
        cur->right = rebuild(preorder_lo + 1 + len, preorder_hi, i + 1, postorder_hi - 1);
        return cur;
    };
    return rebuild(0, preorder.size() - 1, 0, postorder.size() - 1);
}

auto rebuild_from_preorder_inorder_recursive(const vector<int> &preorder,
                                             const vector<int> &inorder) -> TreeNode * {
    function<TreeNode *(int, int, int, int)> rebuild;
    rebuild = [&](int pl, int pr, int il, int ir) -> TreeNode * {
        if (pl > pr || il > ir) return nullptr;
        TreeNode *cur = new TreeNode(preorder[pl]);
        if (pl == pr) return cur;
        int i = il;
        while (inorder[i] != preorder[pl]) i++;
        int len = i - il;
        cur->left = rebuild(pl + 1, pl + len, il, i - 1);
        cur->right = rebuild(pl + 1 + len, pr, i + 1, ir);
        return cur;
    };

    return rebuild(0, preorder.size() - 1, 0, inorder.size() - 1);
}

auto rebuild_from_inorder_postorder_recursive(const vector<int> &inorder,
                                              const vector<int> &postorder) -> TreeNode * {
    function<TreeNode *(int, int, int, int)> rebuild;
    rebuild = [&](int pl, int pr, int il, int ir) -> TreeNode * {
        if (pl > pr || il > ir) return nullptr;
        TreeNode *cur = new TreeNode(postorder[pr]);
        if (pl == pr) return cur;
        int i = il;
        while (inorder[i] != postorder[pr]) i++;
        int len = i - il;
        cur->left = rebuild(pl, pl + len - 1, il, i - 1);
        cur->right = rebuild(pl + len, pr - 1, i + 1, ir);
        return cur;
    };

    return rebuild(0, postorder.size() - 1, 0, inorder.size() - 1);
}