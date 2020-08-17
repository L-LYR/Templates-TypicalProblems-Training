/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
// O(n)
class Solution {
public:
    int reverse(int x) {
        int flag = (x > 0) ? 1 : -1;
        string str_x = to_string(abs(x));
        std::reverse(begin(str_x), end(str_x));
        int ans;
        try {
            ans = flag * stoi(str_x);
        } catch (std::out_of_range& e) {
            return 0;
        }
        return ans;
    }
};
// Test cases:
// 1200 21
// 1563847412 0
// @lc code=end

