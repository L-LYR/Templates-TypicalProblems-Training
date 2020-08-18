/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
// O(s) 
// s is the sum of length of each string.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";
        string ans = strs[0];
        for (int i = 1; i < n; ++i) {
            int j;
            for (j = 0; j < ans.length(); ++j) {
                if (ans[j] != strs[i][j]) break;
            }
            ans = ans.substr(0, j);
        }
        return ans;
    }
};
// @lc code=end

