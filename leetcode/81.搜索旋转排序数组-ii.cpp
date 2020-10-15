/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
// O(logn)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        if (nums.size() == 1) return target == nums[0];
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
    // [l, r]
    int binarySearch(vector<int>& nums, int target, int l, int r) {
        if (l > r) return false;

        // dedup
        while (l < r && nums[l] == nums[l + 1]) l++;
        while (r > l && nums[r - 1] == nums[r]) r--;
        
        int m = (r - l) / 2 + l;        
        if (nums[m] == target) return true;
        if (nums[m] < nums[r]) {
            if (nums[m] < target && target <= nums[r]) 
                return binarySearch(nums, target, m + 1, r);
            else 
                return binarySearch(nums, target, l, m - 1);
        } else {
            if (nums[l] <= target && target < nums[m]) 
                return binarySearch(nums, target, l, m - 1);
            else 
                return binarySearch(nums, target, m + 1, r);
        }
    }
};
// @lc code=end

