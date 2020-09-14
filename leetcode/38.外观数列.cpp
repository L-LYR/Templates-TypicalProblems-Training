/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
// O(F(n))
// F为斐波那契数列通项
class Solution {
public:
    string ans = "1";
    string countAndSay(int n) {
        if (n == 1) return ans;
        ans = describe(ans);
        return countAndSay(n - 1);
    }

    string describe(const string& s) {
        string next = "";
        int i = 0;
        while (i < s.length()) {
            int c = i;
            while (i < s.length() && s[i] == s[c]) {
                i++;
            }
            next += to_string(i - c) + s[c];
        }
        return next;
    }

};
// @lc code=end

