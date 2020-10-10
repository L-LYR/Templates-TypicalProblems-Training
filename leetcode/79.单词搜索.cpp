/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
// O(mn3^l)
class Solution {
public:
    bool search(const vector<vector<char>>& board, const string& word,
                vector<vector<bool>>& visited,
                int i, int j, int n, int m, int cur) {
        if (cur == word.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        int next = cur + 1;
        if (i + 1 < n && !visited[i + 1][j] && board[i + 1][j] == word[next]) {
            if (search(board, word, visited, i + 1, j, n, m, next)) return true;
        }
        if (i - 1 >= 0 && !visited[i - 1][j] && board[i - 1][j] == word[next]) {
            if (search(board, word, visited, i - 1, j, n, m, next)) return true;
        }
        if (j + 1 < m && !visited[i][j + 1] && board[i][j + 1] == word[next]) {
            if (search(board, word, visited, i, j + 1, n, m, next)) return true;
        }
        if (j - 1 >= 0 && !visited[i][j - 1] && board[i][j - 1] == word[next]) {
            if (search(board, word, visited, i, j - 1, n, m, next)) return true;
        }
        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) 
                if(board[i][j] == word[0] && search(board, word, visited, i, j, n, m, 0))
                    return true;
        return false;
    }
};
// @lc code=end

