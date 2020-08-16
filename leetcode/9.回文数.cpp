/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
// O(log(n))
class Solution {

    long get_rev(int x) {
        long rev = 0;
        while (x > 0) {
            rev *= 10;
            rev += x % 10;
            x /= 10;
        }
        return rev;
    }

    bool cmp_half(int x) {
        long half_rev = 0;
        while (x > half_rev) {
            half_rev *= 10;
            half_rev += x % 10;
            x /= 10;
        }
        return half_rev == x || half_rev / 10 == x;
    }

public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        // return get_rev(x) == x;
        // return cmp_half(x);
    }
};
// @lc code=end

