/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
// O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // STL
        // auto last = unique(nums.begin(), nums.end());
        // nums.erase(last, nums.end());
        // return nums.size();

        int i = 0;
        if (nums.size() == 0) return 0;
        for (int j = 1; j < nums.size(); ++j) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        return ++i;
    }
};
// @lc code=end

