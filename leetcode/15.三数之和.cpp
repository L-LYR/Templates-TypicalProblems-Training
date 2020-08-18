/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
// O(n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0) break;

            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ans.push_back(vector<int>({nums[i], nums[l], nums[r]}));

                    while (l < r && nums[r - 1] == nums[r]) r--;
                    while (l < r && nums[l + 1] == nums[l]) l++;
                    r--;
                    l++;

                } else if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

