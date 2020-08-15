/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

// Optimized permutation
// O(n^2)
// TLE
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int len = s.length();
//         if(len == 0) return 0;

//         int ans[len];
//         for(int i = 0; i < len; i++){
//             int j;
//             set<char> alpha;
//             for(j = i; j < len; j++){
//                 char c = s[j];
//                 if(alpha.count(c)) break;
//                 else alpha.insert(c);
//             }
//             if(j == len) ans[i] = len - i;
//             else ans[i] = j - i;
//         }
//         return *max_element(ans, ans + len);
//     }
// };

// sliding-window
// O(n)
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.length();
        if (len == 0)
            return 0;

        int ans = 0, l = 0, r = 0;
        set<char> alpha;

        while (r < len)
        {
            while (alpha.count(s[r]))
            {
                alpha.erase(s[l]);
                ++l;
            }
            alpha.insert(s[r]);
            ans = max(ans, r - l + 1);
            ++r;
        }
        ans = max(ans, r - l); // pay attention

        return ans;
    }
};
// @lc code=end
