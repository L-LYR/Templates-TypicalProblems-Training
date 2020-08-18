/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
// O(2^s)
// s = digits.length()
class Solution {
    vector<string> ans;
    string cur;
    map<char, string> digit_char = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    // simple dfs
    void combine(const string& digits, int dep) {
        if (cur.length() == digits.length()) {
            ans.push_back(cur);
            return;
        }

        for (auto i: digit_char[digits[dep]]) {
            cur.push_back(i);
            combine(digits, dep + 1);
            cur.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        cur = "";
        combine(digits, 0);
        return ans;
    }
};
// @lc code=end

