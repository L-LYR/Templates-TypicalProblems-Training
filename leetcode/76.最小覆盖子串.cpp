/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
// O(N)
class Solution {
   public:
    map<unsigned char, int> tar;
    int cnt[256] = {0};
    bool check() {
        for (auto& i : tar) {
            // cout << i.first << " ";
            if (cnt[i.first] < i.second) {
                return false;
            }
        }
        // cout << endl;
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length();
        if (n == 0 || m == 0 || n < m) return "";
        for (auto& i : t) {
            tar[i]++;
        }
        int l = 0, r = 0;  // [l, r)
        int minLen = INT_MAX, st = 0;
        while (r <= n) {
            // cout << s.substr(l, r - l) << endl;
            int curLen = r - l;
            if (check()) {
                if (minLen > curLen) {
                    minLen = curLen;
                    st = l;
                    if (minLen == m) break;
                }
                cnt[s[l]]--;
                l++;
            } else {
                cnt[s[r]]++;
                r++;
            }
        }
        if (minLen == INT_MAX)
            return "";
        else
            return s.substr(st, minLen);
    }
};
// @lc code=end

