/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start

// O(2^{2n})
// class Solution {
//     vector<string> ans;
//     // dfs
//     void generate(string cur, int l, int r) {
//         if (l == 0 && r == 0) {
//             ans.push_back(cur);
//             return;
//         }

//         if (l > r) return;
//         if (l > 0) generate(cur + "(", l - 1, r);
//         if (r > 0) generate(cur + ")", l, r - 1);
//     }

// public:
//     vector<string> generateParenthesis(int n) {
//         generate("", n, n);
//         return ans;
//     }
// };

// dp
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> dp[n + 1];
        dp[0] = {""};
        dp[1] = {"()"};
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                int k = i - j - 1;
                for (auto js: dp[j]) {
                    for (auto ks: dp[k]) {
                        dp[i].push_back("(" + js + ")" + ks);
                    }
                }
            }
        }
        return dp[n];
    }
};


// @lc code=end

