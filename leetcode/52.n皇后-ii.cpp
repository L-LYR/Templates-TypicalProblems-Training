/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    bool c[20], d1[20], d2[20];
    int ans = 0;
    void search(int n, int i) {
        if (n == i) {
            ans++;
            return;
        }
        for(int j = 0; j < n; ++j) {
            if (c[j] == false && d1[i - j + n] == false && d2[i + j] == false) {
                d2[i + j] = d1[i - j + n] = c[j] = true;
                search(n, i + 1);
                d2[i + j] = d1[i - j + n] = c[j] = false;
            }
        }
    }
    int totalNQueens(int n) {
        search(n, 0);
        return ans;
    }
};
// @lc code=end

