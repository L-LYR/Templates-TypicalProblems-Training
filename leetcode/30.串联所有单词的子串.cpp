/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
// BF
// O(n * m)
// k = words[0].length
// m = words.size()
// n = s.length() - k * m
// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         if (s == "" || words.size() == 0) return {};

//         int word_len = words[0].length();
//         int tot_len = words.size() * word_len;
//         if (s.length() < tot_len) return {};

//         map<string, int> ws;
//         for (const string& str : words) {
//             ws[str]++;
//         }

//         vector<int> ans;
//         for (int i = 0; i <= s.length() - tot_len; ++i) {
//             int j, cnt = 0;
//             auto tmp = ws;
//             for (j = i; !tmp.empty(); j += word_len) {
//                 string cur = s.substr(j, word_len);
//                 if (tmp.count(cur) && tmp[cur] > 0) {
//                     tmp[cur]--;
//                     cnt++;
//                 }
//                 else break;
//             }
//             if (cnt == words.size()) ans.push_back(i);
//         }
//         return ans;
//     }
// };
// [Done] TODO: sliding window
// O(n * m)
// n = words[0].length()
// m = s.length()
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s == "" || words.size() == 0) return {};
        int word_len = words[0].length();
        int tot_len = words.size() * word_len;
        if (s.length() < tot_len) return {};
        int cnt, l, r;
        vector<int> ans;
        unordered_map<string, int> wcnt, window;
        for (string word: words) {
            wcnt[word]++;
        }

        for (int i = 0; i < word_len; ++i) {
            // init
            cnt = 0;
            window.clear();
            r = l = i;
            while (r < s.length()) {
                string next = s.substr(r, word_len);
                if (wcnt.count(next)) {
                    cnt++;
                    window[next]++;
                    r += word_len;
                    while (l < r && window[next] > wcnt[next]) {
                        cnt--;
                        window[s.substr(l, word_len)]--;
                        l += word_len;
                    }
                } else {
                    window.clear();
                    cnt = 0;
                    r += word_len;
                    l = r;
                }

                if (cnt == words.size()) {
                    ans.push_back(l);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

