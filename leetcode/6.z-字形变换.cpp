/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
// O(n)
class Solution
{
public:
    string convert(string s, int numRows)
    {   
        int len = s.length();
        if (len <= 1 || numRows == 1) return s;

        vector<string> res(numRows, "");
        int i = 0, j;
        while (i < len) {
            j = 0;
            while (j < numRows - 1 && i < len)
                res[j++] += s[i++];
            while (j > 0 && i < len)
                res[j--] += s[i++];
        }
        string ans = "";
        for (i = 0; i < numRows; i++) {
            ans += res[i];
        }
        return ans;
    }
};
// @lc code=end
