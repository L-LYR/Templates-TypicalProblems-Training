/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
// O(n^2)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), ans = 0, gap = INT_MAX;
        for (int i = 0; i < n; ++i) {
            // skip the same numbers
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int cur = sum - target;
                if (abs(cur) < gap) {
                    ans = sum;
                    gap = abs(cur);
                }
                // the same logic
                if (cur > 0) {
                    r--;
                } else if (cur < 0) {
                    l++;
                } else {
                    return target; // If equal, return directly.
                }
            }
        }
        return ans;
    }
};
// @lc code=end

