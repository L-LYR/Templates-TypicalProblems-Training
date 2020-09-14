/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
// O(S) 
// S << n * 2^n;
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    void search(vector<int>& nums, int target, int i) {
        if (i == nums.size()) {
            return;
        }
        if (target == 0) {
            ans.push_back(res);
            return;
        }
        if (target >= nums[i]) { // current number can be used
            res.push_back(nums[i]);
            search(nums, target - nums[i], i); 
            res.pop_back();
        }
        search(nums, target, i + 1); // no need to use the current number
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(), candidates.end());
        search(candidates, target, 0);
        return ans;
    }
};
// @lc code=end

