/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
// O(n)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1, max_val = 0;
        while (l < r) {
            int cur = (r - l) * min(height[r], height[l]);
            max_val = max(max_val, cur);
            if (height[r] > height[l]) l++;
            else r--;
        }
        return max_val;
    }
};
// Test cases:
// [1,3,2,5,25,24,5]
// [1,8,6,2,5,4,8,3,7]

// Aim of two pointers:
// Each movement will reduce the data set and make the current result forward to the goal.
// @lc code=end

