/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string m_str, string p_str) {
        if (p_str == "") return 0;
        if (m_str.length() < p_str.length()) return -1;
        
        vector<int> next(p_str.length() + 1, -1);
        int m, p;
        // get next array
        m = 0, p = -1; // -1 is a flag for push pattern-string
        while (m < p_str.length()) {
            while (p != -1 && p_str[p] != p_str[m]) p = next[p];
            // If p == -1, it will make m plus 1 and p will return to 0,
            // which means the match will restart at next char in 
            // match-string from the first char of pattern-string.
            ++p;
            ++m;
            next[m] = p;
        }
        // search in match-string
        m = 0, p = 0;
        while (m < m_str.length()) {
            cout << m << " " << p << endl;
            while (p != -1 && p_str[p] != m_str[m]) p = next[p];
            ++m;
            ++p;
            if (p == p_str.length()) return m - p;
        }

        return -1;
    }
};
// @lc code=end

