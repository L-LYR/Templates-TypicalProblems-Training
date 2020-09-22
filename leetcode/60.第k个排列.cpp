/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
// O(nk)
// TODO: fullfill the math method
// Expected O(n^2)
class Solution {
public:
    
    string getPermutation(int n, int k) {
        string ans;
        for (int i = 1; i <= n; i++) {
            ans.push_back(i + '0');
        }
        for (int i = 1; i < k; ++i)
            next_permutation(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

