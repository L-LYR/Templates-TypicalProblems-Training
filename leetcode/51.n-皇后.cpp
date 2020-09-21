/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;
    bool c[20], d1[20], d2[20];
    void search(int n, int i, vector<string>& res) {
        if (n == i) {
            ans.push_back(res);
            return;
        }

        for(int j = 0; j < n; ++j) {
            if (c[j] == false && d1[i - j + n] == false && d2[i + j] == false) {
                res[i][j] = 'Q';
                d2[i + j] = d1[i - j + n] = c[j] = true;
                search(n, i + 1, res);
                d2[i + j] = d1[i - j + n] = c[j] = false;
                res[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> res(n, string(n, '.'));
        search(n, 0, res);
        return ans;
    }
};
// @lc code=end

