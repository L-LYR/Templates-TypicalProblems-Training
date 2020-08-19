/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
// BF
// TODO: sliding window
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s == "" || words.size() == 0) return {};

        int word_len = words[0].length();
        int tot_len = words.size() * word_len;
        if (s.length() < tot_len) return {};

        map<string, int> ws;
        for (const string& str : words) {
            ws[str]++;
        }

        vector<int> ans;
        for (int i = 0; i <= s.length() - tot_len; ++i) {
            int j, cnt = 0;
            auto tmp = ws;
            for (j = i; !tmp.empty(); j += word_len) {
                string cur = s.substr(j, word_len);
                if (tmp.count(cur) && tmp[cur] > 0) {
                    tmp[cur]--;
                    cnt++;
                }
                else break;
            }
            if (cnt == words.size()) ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

