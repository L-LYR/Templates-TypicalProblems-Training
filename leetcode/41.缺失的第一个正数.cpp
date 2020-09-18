/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
// O(n)
// Use hash
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 1;
        for (int i = 0; i < len; ++i) { // set number, which is out of range, to len + 1
            if (nums[i] <= 0 || nums[i] > len) {
                nums[i] = len + 1;
            }
        }
        for (int i = 0; i < len; ++i) { // set nums[nums[i] - 1] to negative
            int n = abs(nums[i]);
            if (n <= len && nums[n - 1] > 0) {
                nums[n - 1] = -nums[n - 1];
            }
        }
        int first = 0;
        while (first < len) { // the index of the first positive one is the answer
            if (nums[first] > 0) break;
            first++;
        }
        return first + 1;
    }
};
// @lc code=end

