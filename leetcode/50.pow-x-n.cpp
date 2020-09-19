/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
// quick power
// O(logn)
class Solution {
public:
    double myPow(double x, int n) {
        double base = x;
        double ans = 1;
        int m = abs(n);

        while (m > 0) {
            if (m & 1) {
                ans *= base;
            }
            base *= base;
            m >>= 1;
        }
        if (n < 0) return 1.0 / ans;
        else return ans;
    }
};
// @lc code=end

