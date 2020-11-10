/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        if (s.length() == 1) return 1;
        int dp[205];
        memset(dp, 0, sizeof(dp));
        dp[0] = dp[1] = 1;
        int i = 1;
        while (i < s.length()) {
            if (s[i] == '0') {
                if ((s[i - 1] == '1' || s[i - 1] == '2')) 
                    dp[i + 1] = dp[i - 1];
                else return 0;
            } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                dp[i + 1] = dp[i] + dp[i - 1];
            } else {
                dp[i + 1] = dp[i];
            }
            i++;
        }
        return dp[i];
    }
};
// @lc code=end

