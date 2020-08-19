/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
// pay attention to the overflow and method!!!
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sd = dividend >> 31, sr = divisor >> 31;
        int sa = (sd ^ sr);
        // cout << sd << " " << sr << " " << sa << endl;
        long long ans = 0;
        long long abs_d = abs(dividend), abs_r = abs(divisor);
        for (int i = 31; i >= 0; --i) {
            if ((abs_d >> i) >= abs_r) {
                ans += (long long)1 << i;
                abs_d -= abs_r << i;
            }
        }
        // cout << ans;
        if (sa) ans = ~(ans) + 1;
        if (ans > INT_MAX) return INT_MAX;
        else return (int)ans;
    }
};
// @lc code=end