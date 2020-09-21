/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
// O(n)
// dp: f(n) = max(nums[n], nums[n] + f(n - 1))
// f(i) means the sum of the sub-array whose end element is nums[i].
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int prev = nums[0], ans = nums[0];
        for (int i = 1; i < n; ++i) {
            prev = max(nums[i], nums[i] + prev);
            ans = max(ans, prev);
        }
        return ans;
    }
};
// @lc code=end

