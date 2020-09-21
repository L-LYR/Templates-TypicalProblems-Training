/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
// O(mn)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return {};
        int n = matrix[0].size();
        if (n == 0) return {};
        vector<int> ans;
        int i = 0, j = 0, k = 0;
        while (2 * k < m && 2 * k < n) {
            for (j = i = k; j <= n - k - 1; ++j) 
                ans.push_back(matrix[i][j]);
            for (++i, --j; i <= m - k - 1; ++i)
                ans.push_back(matrix[i][j]);
                // The reverse traverse should be judged.
            if (m - k - 1 > k)
                for (--j, --i; j >= k; --j)
                    ans.push_back(matrix[i][j]);
            if (k < n - k - 1)
                for (--i, ++j; i > k; --i)
                    ans.push_back(matrix[i][j]);
            ++k;
        }
        return ans;
    }
};
// @lc code=end

