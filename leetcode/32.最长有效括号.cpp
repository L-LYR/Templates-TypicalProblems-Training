/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
// O(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() == 0) return 0;
        int dp[s.length()];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == ')') { // no need to care about '(', which is always be 0.
                if (s[i - 1] == '(') {                                              // "...()".
                    if (i > 2)
                        dp[i] = dp[i - 2] + 2;
                    else 
                        dp[i] = 2;
                } else if (s[i - 1] == ')') {                                       // "...))"
                    if (i - 1 - dp[i - 1] >= 0 && s [i - 1 - dp[i - 1]] == '(') {   // "...((...))"
                        if (i - 2 - dp[i - 1] >= 0)                                 // "(...)((...))"
                            dp[i] = dp[i - 1] + dp[i - 2 - dp[i - 1]] + 2;
                        else                                                        // "((...))"
                            dp[i] = dp[i - 1] + 2;
                    } else                                                          // "((...)))" or ")(...))"
                        dp[i] = 0;
                }
            }
        }
        return *max_element(dp, dp + s.length());
    }
};
// @lc code=end

