/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
// O(n)
class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1) return;
        int l = 0, r = n - 1, m = l;
        while (m <= r) {
            if (nums[m] == 0) {
                swap(nums[m], nums[l]);
                l++;
                m++;  // nums[l] has been checked by m before
            } else if (nums[m] == 2) {
                swap(nums[m], nums[r]);
                r--;
            } else
                m++;
        }
    }
};
// @lc code=end
