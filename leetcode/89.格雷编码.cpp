/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
// O(2^n)
class Solution {
public:
    vector<int> grayCode(int n) {
        int lim = 1 << n;
        vector<int> ans;
        for (int i = 0; i < lim; ++i) {
            ans.push_back(i ^ i >> 1);
        }
        return ans;
    }
};
// @lc code=end

