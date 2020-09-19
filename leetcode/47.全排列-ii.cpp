/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
// The same with the previous one.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end(), less<int>()); // O(nlogn)
        ans.push_back(nums);
        while(nextPermutation(nums)) { // O(n*n!)
            ans.push_back(nums);
        }
        return ans;
    }
    bool nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        int j = n - 1;
        while (j >= 0 && nums[j] >= nums[j + 1]) {
            j--;
        }
        if (j >= 0) {
            int k = n;
            while (k >= 0 && nums[j] >= nums[k]) {
                k--;
            }
            swap(nums[j], nums[k]);
        }
        reverse(next(nums.begin(), j + 1), next(nums.begin(), n + 1));
        if (j == -1)
            return false;
        else
            return true;
    }
};
// @lc code=end

