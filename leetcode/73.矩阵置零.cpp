/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
    int m, n;
    void setVal(int r, int c, vector<vector<int>>& mt) {
        for (int i = 0; i < m; ++i) {
            if (mt[i][c] != 0) mt[i][c] = 0x3F3F3F3F;
        }
        for (int i = 0; i < n; ++i) {
            if (mt[r][i] != 0) mt[r][i] = 0x3F3F3F3F;
        }
    }

   public:
    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m == 0) return;
        n = matrix[0].size();
        if (n == 0) return;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][j] = 0x3F3F3F3F;
                    setVal(i, j, matrix);
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0x3F3F3F3F) {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};
// @lc code=end
