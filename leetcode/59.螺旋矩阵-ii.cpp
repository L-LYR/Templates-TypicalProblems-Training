/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
// The same with problem 54.
// O(n^2)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int k = 0, i, j, n2 = 1;
        while (2 * k < n) {
            for (i = k, j = k; j <= n - k - 1; ++j)
                ans[i][j] = n2++;
            for (--j, ++i; i <= n - k - 1; ++i)
                ans[i][j] = n2++;
            if (k < n - k - 1)
                for (--i, --j; j >= k; --j)
                    ans[i][j] = n2++;
            if (k < n - k - 1)
                for (--i, ++j; i > k; --i)
                    ans[i][j] = n2++;
            k++;
        }
        return ans;
    }
};
// @lc code=end

