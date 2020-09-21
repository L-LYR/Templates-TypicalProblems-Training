/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
// O(n)
// Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int max_path = 0;
        for (int i = 0; i < n; ++i) {
            max_path = max(max_path, nums[i] + i);
            if (i == r) {
                r = max_path;
            }
        }
        if (r >= n - 1) return true;
        else return false;
    }
};
// @lc code=end

