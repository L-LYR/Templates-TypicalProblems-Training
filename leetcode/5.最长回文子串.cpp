/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start

// dynamic programming
// O(n^2)
// dp[l][r] means sub-string s[l..r] is palindrome.
// State Transmition Equation:
//      dp[l][r] = (s[l] == s[r]) && (dp[l + 1][r - 1])     (r - l >= 2)
//      dp[l][r] = true                                     (r - l = 0)
//      dp[l][r] = (s[l] == s[r])                           (r - l = 1)

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0 || len == 1) return s;
        
        bool dp[len][len];
        for(int i = 0; i < len; ++i) dp[i][i] = true; // Initialization

        int maxLen = 1, begin = 0;
        for(int r = 1; r < len; ++r){
            for(int l = 0; l < r; ++l){
                dp[l][r] = (s[l] == s[r]);

                int curLen = r - l + 1;
                if(curLen >= 3) dp[l][r] &= dp[l + 1][r - 1];

                if(!dp[l][r]) continue;

                if(curLen > maxLen){
                    maxLen = curLen;
                    begin = l;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
// @lc code=end

