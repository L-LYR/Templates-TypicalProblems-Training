/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */

// @lc code=start
class Solution {
   public:
    vector<string> fullJustify(vector<string>& words, int mw) {
        if (words.empty()) return {};
        vector<string> ans;
        int st = 0;
        int cur = 0;
        for (int i = 0; i < words.size(); ++i) {
            cur += words[i].length() + 1;
            if (i + 1 == words.size()) {
                string ret = words[st];
                for (int j = st + 1; j < words.size(); ++j) {
                    ret.append(" " + words[j]);
                }
                ret.append(mw - cur + 1, ' ');
                ans.push_back(ret);
                break;
            }

            if (cur + words[i + 1].length() > mw) {
                ans.push_back(line(words, st, i, mw, cur));
                st = i + 1;
                cur = 0;
            }
        }
        return ans;
    }

    string line(vector<string>& words, int l, int r, int mw, int cur) {
        string ret = "";
        int n = r - l + 1, extra, left;
        if (n == 1) {
            ret.append(words[l]);
            ret.append(mw - words[l].length(), ' ');
            return ret;
        }

        if (n > 1) {
            extra = (mw - cur + 1) / (n - 1);
            left = (mw - cur + 1) % (n - 1);
        }
        for (int i = l; i <= r; ++i) {
            if (i > l) {
                ret.append(" ");
                ret.append(extra, ' ');
                if (left > 0) {
                    ret.append(" ");
                    left--;
                }
            }
            ret.append(words[i]);
        }

        return ret;
    }
};
// ["This", "is", "an", "example", "of", "text", "justification."] 16
// ["What", "must", "be", "acknowledgment", "shall", "be"] 16
// ["Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"] 20
// @lc code=end
