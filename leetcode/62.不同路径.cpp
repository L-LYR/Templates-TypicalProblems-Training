/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
// O(mn)
// simple dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        dp[1][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

