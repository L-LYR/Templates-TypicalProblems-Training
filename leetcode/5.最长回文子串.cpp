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

// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         int len = s.length();
//         if (len == 0 || len == 1)
//             return s;

//         bool dp[len][len];
//         for (int i = 0; i < len; ++i)
//             dp[i][i] = true; // Initialization

//         int maxLen = 1, begin = 0;
//         for (int r = 1; r < len; ++r)
//         {
//             for (int l = 0; l < r; ++l)
//             {
//                 dp[l][r] = (s[l] == s[r]);

//                 int curLen = r - l + 1;
//                 if (curLen >= 3)
//                     dp[l][r] &= dp[l + 1][r - 1];

//                 if (!dp[l][r])
//                     continue;

//                 if (curLen > maxLen)
//                 {
//                     maxLen = curLen;
//                     begin = l;
//                 }
//             }
//         }
//         return s.substr(begin, maxLen);
//     }
// };

// Centre Spreading Method
// O(n^2)
// class Solution
// {
// public:
//     string spread(string s, int l, int r){
//         int len = s.length();
//         while ( l >=0 && r < len)
//         {
//             if (s[l] == s[r])
//             {
//                 l--;
//                 r++;
//             }
//             else 
//                 break;
//         }
//         return s.substr(l + 1, r - l - 1);
//     }

//     string longestPalindrome(string s)
//     {
//         int len = s.length();
//         if (len == 0 || len == 1)
//             return s;
//         int maxLen = 1;
//         string res = s.substr(0, 1);
//         for (int i = 0; i < len - 1; i++)
//         {
//             string odd = spread(s, i, i);
//             string even = spread(s, i, i + 1);
//             string maxLenStr = odd.length() < even.length() ? even : odd;
//             if (maxLenStr.length() > maxLen) 
//             {
//                 maxLen = maxLenStr.length();
//                 res = maxLenStr;
//             }
//         }
//         return res;
//     }
// };

// TODO: Manachar Algorithm
// O(n)

class Solution
{
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0 || len == 1)
            return s;

        
    }
}

// @lc code=end
