/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
// O(n)
// two pointer
class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        if (n == 0) return 0;
        int sum = 0, l = 1, r = n - 2;
        int l_max = 0, r_max = 0;
        while (l <= r) {
            if (h[l - 1] < h[r + 1]) {
                // the lower side will be filled with water definitely!!!!
                l_max = max(l_max, h[l - 1]);
                if (l_max > h[l]) {
                    sum += l_max - h[l];
                }
                ++l;
            } else {
                r_max = max(r_max, h[r + 1]);
                if (r_max > h[r]) {
                    sum += r_max - h[r];
                }
                --r;
            }
        }
        return sum;
    }
};
// @lc code=end

