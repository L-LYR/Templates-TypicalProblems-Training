/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
// O(N^4)
class Solution {
public:
    bool isScramble(string s1, string s2) {
        // general search
        if (s1 == s2) return true;
        int n = s1.length();
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; ++i) {
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0) return false;
        }
        for (int k = 1; k < n; ++k) {
            // s1[0...k] == s2[0...k]
            // s1[k+1...n] == s2[k+1...n]
            bool left = isScramble(s1.substr(0, k), s2.substr(0, k));
            bool right = isScramble(s1.substr(k), s2.substr(k));
            if (left && right) return true;
            // s1[0...k] == s2[n-k...n]
            // s1[k+1...n] == s2[0...n-k]
            left = isScramble(s1.substr(0, k), s2.substr(n - k));
            right = isScramble(s1.substr(k), s2.substr(0, n - k));
            if (left && right) return true;
        }
        return false;
    }
};
// @lc code=end

