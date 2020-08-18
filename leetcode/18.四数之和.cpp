/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
// O(n^3)
// same algorithm with Problem 15
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            // skip the same numbers
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n; ++j) {
                // skip the same numbers
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int l = j + 1, r = n - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        ans.push_back(
                            vector<int>({nums[i], nums[j], nums[l], nums[r]})
                        );
                        // skip the same numbers
                        while (l < r && nums[r - 1] == nums[r]) r--;
                        while (l < r && nums[l + 1] == nums[l]) l++;
                        r--;
                        l++;
                    } else if (sum < target) {
                        l++;
                    } else if (sum > target) {
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

