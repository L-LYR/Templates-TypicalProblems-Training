/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;

        int r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (matrix[r][c] < target)
                r++;
            else if (matrix[r][c] > target)
                c--;
            else
                return true;
        }
        // Binary Search O(log(mn))
        // int l = 0, r = m * n - 1;
        // while (l <= r) {
        //     int mid = (r - l) / 2 + l;
        //     int mv = matrix[mid / n][mid % n];
        //     if (mv == target)
        //         return true;
        //     else if (mv > target)
        //         r = mid - 1;
        //     else if (mv < target)
        //         l = mid + 1;
        // }

        return false;
    }
};
// @lc code=end
