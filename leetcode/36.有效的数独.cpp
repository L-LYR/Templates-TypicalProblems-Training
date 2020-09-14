/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
// O(k)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> l[9], c[9], b[3][3];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch == '.') continue;
                if (l[i].count(ch) == 1 || 
                    c[j].count(ch) == 1 ||
                    b[i / 3][j / 3].count(ch) == 1) 
                    return false;
                l[i].insert(ch);
                c[j].insert(ch);
                b[i / 3][j / 3].insert(ch);
            }
        }
        return true;
    }
};
// @lc code=end

