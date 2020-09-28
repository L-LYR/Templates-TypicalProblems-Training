/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1,j = b.size() - 1;
        int carryIn = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || carryIn) {
            int res = carryIn;
            if (i >= 0) {
                res += (a[i] - '0');
                --i;
            }
            if (j >= 0) {
                res += (b[j] - '0');
                --j;
            }
            carryIn = res / 2;
            ans.push_back('0' + res % 2);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

