/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    // O(mn^2)
    // n = strs.size()
    // m = maxLen(strs[i])
    // TLE
    // int c[26];
    // int cnt = 0;
    // void setList(const string& word) {
    //     memset(c, 0, sizeof(c));
    //     for (auto i : word) {
    //         c[i - 'a']++;
    //     }
    //     cnt = word.length();
    // }

    // bool judge(const string& word) {
    //     int tc[26];
    //     int tcnt = cnt;
    //     memcpy(tc, c, 26 * sizeof(int));
    //     for (auto i : word) {
    //         if (tc[i - 'a'] > 0) {
    //             tc[i - 'a']--;
    //             tcnt--;
    //         } else {
    //             return false;
    //         }
    //     }
    //     if (tcnt == 0) return true;
    //     else return false;
    // }
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //     vector<vector<string>> ans;
    //     vector<string> tmp;
    //     int n = strs.size();
    //     bool used[n];
    //     memset(used, false, sizeof(used));
    //     for (int i = 0; i < n; ++i) {
    //         if (used[i]) continue;
    //         setList(strs[i]);
    //         tmp.push_back(strs[i]);
    //         used[i] = true;
    //         for (int j = i + 1; j < n; ++j) {
    //             if (!used[j] && judge(strs[j])) {
    //                 tmp.push_back(strs[j]);
    //                 used[j] = true;
    //             }
    //         }
    //         ans.push_back(tmp);
    //         tmp.clear();
    //     }
    //     return ans;
    // }
    
    // O(nmlogm)
    // n = strs.size()
    // m = maxLen(strs[i])
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> smv; // sorted string and index in answer vector
        vector<vector<string>> ans;
        int n = strs.size();
        string tmp;
        for (int i = 0; i < n; ++i) { // O(n)
            tmp = strs[i];
            sort(tmp.begin(), tmp.end()); // O(mlogm)
            if (smv.count(tmp)) {
                ans[smv[tmp]].push_back(strs[i]);
            } else {
                ans.push_back({strs[i]});
                smv[tmp] = ans.size() - 1;
            }
        }
        return ans;
    }
};
// @lc code=end

