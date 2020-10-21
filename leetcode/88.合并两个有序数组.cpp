/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
// O(m + n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tol = m + n - 1;
        while (n > 0) {
            if (m == 0 || nums1[m - 1] <= nums2[n - 1])
                nums1[tol--] = nums2[--n];
            else 
                nums1[tol--] = nums1[--m];
        }
    }
};
// @lc code=end

