/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
// O(n)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        int n = nums.size() - 1;
        if (n == 0) return;

        // From right to left, find the first num 
        // which satisfies nums[j] < nums[j + 1].
        int j = n - 1;
        while (j >= 0 && nums[j] >= nums[j + 1]) {
            j--;
        }

        // nums[j] exists
        if (j >= 0) {
            // From right to left, find the first num
            // which satisfies nums[k] > nums[j].
            int k = n;
            while (k >= 0 && nums[j] >= nums[k]) {
                k--;
            }
            swap(nums[j], nums[k]);
        }

        // reverse num[j + 1....n]
        int r = n;
        int s = j + 1;
        while (r > s) {
            swap(nums[r], nums[s]);
            r--;
            s++;
        }
    }
};
// @lc code=end

