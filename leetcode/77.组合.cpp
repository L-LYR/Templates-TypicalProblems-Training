/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
// O(C(n, k))
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void dfs(int st, int range, int lim, int dep) {
        if (dep == lim) {
            ans.push_back(cur);
            return;
        }
        while (st <= range) {
            cur.push_back(st);
            dfs(st + 1, range, lim, dep + 1);
            cur.pop_back();
            st++;
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if (k == 0 || n < k) return {};
        dfs(1, n, k, 0);
        return ans;       
    }
};
// @lc code=end

