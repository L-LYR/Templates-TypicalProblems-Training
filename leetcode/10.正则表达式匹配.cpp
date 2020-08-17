/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
// O(mn)
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n + 1][m + 1];

        memset(dp, false, sizeof(dp));
        dp[0][0] = true; // basic case: s = "" and p = ""
        for (int i = 0; i < m; ++i) { // initialization
            if (p[i] == '*' && dp[0][i - 1]) { // for example: s = "" and p = "a*"
                dp[0][i + 1] = true;
            }
        }
        
        // dp[i + 1][j + 1] means that s[0...i] is satisfied to p[0...j].
        // State Transmition Equation:

        // case 1 & 2: p[j] == s[i] or p[j] == '.'
        // dp[i + 1][j + 1] = dp[i][j]
        // s[0...i] fits p[0...j] which depends on whether s[0...i-1] fits p[0...j-1].

        // case 3: p[j] == '*'
        // Pay attention to the previous charactor p[j - 1].
        //
        // subcase 1: p[j - 1] != s[i] and p[j - 1] != '.'
        // dp[i + 1][j + 1] = dp[i + 1][j - 1]
        // Here the '*' will match zero p[j - 1].
        // s[0...i] fits p[0...j] which depends on whether s[0...i] fits p[0...j-1].
        // 
        // subcase 2: p[j - 1] == s[i] or p[j - 1] == '.'
        // dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j - 1]
        // Pay attention to how to match here.
        // '*' matches multiple p[j - 1], so it depends on whether s[0...i-1] fits p[0...j].
        // '*' matches single p[j - 1], so it depends on whether s[0...i] fits p[0...j-1].
        // '*' matches nothing, so it depends on whether s[0...i] fits p[0...j-2].


        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (p[j] == '.' || p[j] == s[i]) {
                    dp[i + 1][j + 1] = dp[i][j]; 
                } else if (p[j] == '*') {
                    if (p[j - 1] != s[i] && p[j - 1] != '.') {
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    } else {
                        dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j] || dp[i + 1][j - 1];
                    }
                }
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

