/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
// O(log(n))
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
    // [l, r]
    int binarySearch(vector<int>& nums, int target, int l, int r) {
        if (l > r) return -1;
        
        int m = (r - l) / 2 + l;        
        if (nums[m] == target) return m;

        // After divided, there must be a sorted part and a unsorted one.
        // If target in the sorted part, use binary search.
        // If target in the unsorted part, use the division procedure above repeatedly.
        
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

