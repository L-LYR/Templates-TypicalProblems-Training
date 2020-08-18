/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
// O(1)
class Solution {
        map<char, int> roman_digit = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
public:
    int romanToInt(string s) {
        int len = s.length(), i = len - 2, ans = roman_digit[s.back()];
        while (i >= 0) {
            
            // int flag = 1;
            // if (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')){
            //     flag = -1;
            // } else if (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
            //     flag = -1;
            // } else if (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
            //     flag = -1;
            // }
            // ans += flag * roman_digit[s[i]];

            if (roman_digit[s[i]] < roman_digit[s[i + 1]])
                ans -= roman_digit[s[i]];
            else 
                ans += roman_digit[s[i]];

            i--;
        }
        return ans;
    }
};
// Test cases:
// "III"
// "IV"
// "IX"
// "LVIII"
// "MCMXCIV"
// "MMVII"
// 3
// 4
// 9
// 58
// 1994
// 2007
// @lc code=end

