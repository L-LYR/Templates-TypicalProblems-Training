/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
// O(2^n)
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void search(const vector<int>& nums, vector<bool>& visited, int i) {
        ans.push_back(cur);
        for (int j = i; j < nums.size(); ++j) {
            // The previous one is not used.
            if (j > 0 && nums[j] == nums[j - 1] && !visited[j - 1]) {
                continue;
            }
            cur.push_back(nums[j]);
            visited[j] = true;
            search(nums, visited, j + 1);
            cur.pop_back();
            visited[j] = false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        search(nums, visited, 0);
        return ans;
    }
};
// @lc code=end

