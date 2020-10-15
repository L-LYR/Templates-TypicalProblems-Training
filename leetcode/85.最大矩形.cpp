/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
// O(nm)
// converted to Problem 84
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0;
        int m = matrix[0].size();
        if (m == 0) return 0;
        int sz = m + 2;
        vector<int> curRow(sz, 0);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < sz - 1; ++j) {
                if (matrix[i][j - 1] == '1') curRow[j]++;
                else curRow[j] = 0;
            }
            stack<int> is;
            for (int j = 0; j < sz; ++j) {
                while (!is.empty() && curRow[is.top()] > curRow[j]) {
                    int cur = curRow[is.top()];
                    is.pop();
                    ans = max(ans, (j - 1 - is.top()) * cur);
                }
                is.push(j);
            }
        }
        return ans;
    }
};
// @lc code=end

