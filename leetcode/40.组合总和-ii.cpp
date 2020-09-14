/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
// O(S) 
// S << n * 2^n;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    void solve(vector<int>& nums, int target, int i) {
        if (target == 0) {
            ans.push_back(res);
            return;
        }
        if (i == nums.size()) {
            return;
        }
        if (target >= nums[i]) {
            res.push_back(nums[i]);
            solve(nums, target - nums[i], i + 1);
            res.pop_back();
        }
        int cur = nums[i];
        while(i < nums.size() && nums[i] == cur) {
            ++i;
        }
        solve(nums, target, i);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return ans;
    }
};
// @lc code=end

