/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
// O(mn)
// DP
class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = i;
        }
        for (int i = 0; i <= m; ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word2[i - 1] == word1[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // replace: dp[i - 1][j - 1]
                    // remove:  dp[i][j - 1]
                    // insert:  dp[i - 1][j]
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }

        // for (int i = 0; i <= m; ++i) {
        //     for (int j = 0; j <= n; ++j) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[m][n];
    }
};
// @lc code=end
