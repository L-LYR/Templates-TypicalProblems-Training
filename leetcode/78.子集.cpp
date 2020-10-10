/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
// O(2^n)
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void dfs(vector<int>& nums, int lim, int dep, int st) {
        if (dep == lim) {
            ans.push_back(cur);
            return;
        }
        while (st < nums.size()) {
            cur.push_back(nums[st]);
            dfs(nums, lim, dep + 1, st + 1);
            cur.pop_back();
            st++;
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        ans.push_back({});
        ans.push_back(nums);
        for (int i = 1; i < n; ++i) dfs(nums, i, 0, 0);
        return ans;
    }
};
// @lc code=end

