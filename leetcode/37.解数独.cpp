/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    set<char> l[9], c[9], b[3][3];
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char ch = board[i][j];
                if (ch != '.') {
                    l[i].insert(ch);
                    c[j].insert(ch);
                    b[i / 3][j / 3].insert(ch);
                }
            }
        }
        solve(board, 0, 0);
    }
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solve(board, i + 1, 0);
        if (board[i][j] != '.') return solve(board, i, j + 1);
        for (char k = '1'; k <= '9'; ++k) {
            if (l[i].count(k) == 0 &&
                c[j].count(k) == 0 &&
                b[i / 3][j / 3].count(k) == 0) {

                l[i].insert(k);
                c[j].insert(k);
                b[i / 3][j / 3].insert(k);

                board[i][j] = k;
                if (solve(board, i, j + 1))
                    return true;
                board[i][j] = '.';

                l[i].erase(k);
                c[j].erase(k);
                b[i / 3][j / 3].erase(k);
            }
        }
        return false;
    }
};
// @lc code=end

