/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
// O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int l = 0, r = 0;
        while (r < nums.size()) {
            int cur = nums[r], cnt = 2;
            while (r < nums.size() && nums[r] == cur) {
                r++;
                if (cnt > 0) { // save the first cnt numbers
                    nums[l++] = cur;
                    cnt--;
                }            
            }
        }
        return l;
    }
};
// @lc code=end

