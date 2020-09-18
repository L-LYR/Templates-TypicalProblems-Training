/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
// O(mn)
// m = s.length()
// n = p.length()
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool dp[m + 1][n + 1];
        // here we set index begin from 1.
        // str[0] means ""
        // dp[i][j] means s[1...i] is matched by p[1...j]
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;

        // State Transmition Equation:

        // Initialization: dp[0][0] = true and set others to false;

        // Case 1: If p[i - 1] is '*', 
        // firstly dp[0][i] = dp[0][i - 1], 
        // which means '*' matches a whole null string, 
        // and then for all j in [1, m], 
        // dp[j][i] = dp[j - 1][i] || dp[j][i - 1], 
        // the former means '*' matches the rest charactors,
        // the later means '*' matches a null string,

        // Case 2: If p[i - 1] is '?',
        // dp[j][i] = dp[j - 1][i - 1],
        // which means '?' matches the last charactor.

        // Case 3: If p[i - 1] is equal to s[j - 1],
        // dp[j][i] = dp[j - 1][i - 1] for the same reason with case 2.
        
        for(int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 1];
                for (int j = 1; j <= m; ++j) {
                    dp[j][i] = dp[j - 1][i] || dp[j][i - 1];
                }
            } else if (p[i - 1] == '?') {
                for (int j = 1; j <= m; ++j) {
                    dp[j][i] = dp[j - 1][i - 1];
                }
            } else {
                for (int j = 1; j <= m; ++j) {
                    if(p[i - 1] == s[j - 1]) {
                        dp[j][i] = dp[j - 1][i - 1];
                    }
                }
            }
        }

        // for debug
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

