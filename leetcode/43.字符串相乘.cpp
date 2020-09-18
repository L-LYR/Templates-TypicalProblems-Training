/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
// O(mn)
// m = num1.length() n = num2.length()
// simulation
class Solution {
public:
    string multiplyByDigit(string num, int d) {
        int len = num.length(), s = 0, c = 0;
        for (int i = len - 1; i >= 0; i--) {
            s = (num[i] - '0') * d + c;
            num[i] = s % 10 + '0';
            c = s / 10;
        }
        if (c != 0) num.insert(0, 1, c + '0');
        return num;
    }
    string add(string num1, string num2) {
        if (num1.length() > num2.length()) return add(num2, num1);
        int len = num2.length(), s, c = 0;
        num1.insert(0, len - num1.length(), '0');
        for (int i = len - 1; i >= 0; i--) {
            s = (num1[i] - '0') + (num2[i] - '0') + c;
            num1[i] = s % 10 + '0';
            c = s / 10;
        }
        if (c != 0) num1.insert(0, 1, c + '0');
        return num1;
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        if (num1.length() > num2.length()) return multiply(num2, num1);
        int len = num1.length();
        string ans, tmp;
        for (int i = len - 1; i >= 0; i--) {
            tmp = multiplyByDigit(num2, num1[i] - '0');
            tmp.append(len - 1 - i, '0');
            ans = add(ans, tmp);
        }
        return ans;
    }
};
// @lc code=end

