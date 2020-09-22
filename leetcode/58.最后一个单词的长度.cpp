/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start

// Learn to use the std::regex
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0;
        for (i = s.length(); i > 0; i--) {
            if (isalpha(s[i - 1])) break;
        }
        if (i < s.length())
            s = s.substr(0, i);
        if (s == "") return 0;
        regex reg("([^\\s]+)\\s*$");
        smatch sm;
        regex_search(s, sm, reg);
        // cout << sm[0] << endl;
        return sm[0].length();
    }
};
// @lc code=end

