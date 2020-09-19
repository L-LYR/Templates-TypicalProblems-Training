/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
// To rotate 90 degrees clockwise is equal to a combination
// of making a diagonal symmetric operation and making a
// horizontal symmetric one. 
class Solution {
public:
    void diagonalSymmetry(vector<vector<int>>& m) {
        int n = m.size();
        int s = n - 1; // symmetry factor
        for (int i = s; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                swap(m[s - i][j], m[abs(j - s)][i]);
            }
        }
    }

    void horizonSymmetry(vector<vector<int>>& m) {
        int n = m.size();
        int s = n - 1;
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(m[i][j], m[abs(i - s)][j]);
            }
        }
    }

    // void print(vector<vector<int>>& m) {
    //     for (int i = 0; i < m.size(); ++i) {
    //         for (int j = 0; j < m.size(); ++j) {
    //             cout << m[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    void rotate(vector<vector<int>>& matrix) {
        // print(matrix);
        diagonalSymmetry(matrix);
        // print(matrix);
        horizonSymmetry(matrix);
        // print(matrix);
    }
};
// @lc code=end

