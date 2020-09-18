/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    // DFS TLE!
    // int ans = INT_MAX;
    // void search(vector<int>& nums, int pos, int dep) {
    //     if (pos == nums.size() - 1) {
    //         ans = min(ans, dep);
    //         return;
    //     }
    //     int next;
    //     for (int i = 1; i <= nums[pos]; ++i) {
    //         next = pos + i;
    //         if (next < nums.size()) {
    //             search(nums, next, dep + 1);
    //         }
    //     }
    // }
    // int jump(vector<int>& nums) {
    //     int n = nums.size();
    //     search(nums, 0, 0);
    //     return ans;
    // }
    // O(n)
    int jump(vector<int>& nums) {
        int n = nums.size();
        int r = 0;
        int max_path = 0;
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            // find the farthest bound
            // Just be greedy!!!!
            max_path = max(max_path, nums[i] + i);
            if (i == r) {
                r = max_path;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

