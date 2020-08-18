/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
// O(1)
class Solution {
    map<int, string> roman_digit = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"},
    };

public:
    string intToRoman(int num) {
        string ans = "";
        int digit, base = 1;
        for (int i = 0; i < 4; i++) {
            string cur = "";
            digit = num % 10;
            // cout << digit << " ";
            if (digit == 4) {
                cur = roman_digit[base * 4];
            } else if (digit == 9) {
                cur = roman_digit[base * 9];
            } else if (digit >= 5) {
                cur = roman_digit[base * 5];
                digit -= 5;
            }
            if (digit < 4) {
                while(digit > 0) {
                    cur += roman_digit[base];
                    digit--;
                }
            }
            // cout << cur << endl;
            num /= 10;
            base *= 10;
            ans = cur + ans;
        }
        return ans;
    }
};

// Test case:
// 3
// 4
// 9
// 58
// 1994
// 2007
// "III"
// "IV"
// "IX"
// "LVIII"
// "MCMXCIV"
// "MMVII"
// @lc code=end

