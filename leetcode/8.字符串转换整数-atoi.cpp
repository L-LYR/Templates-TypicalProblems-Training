/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start

// class Automaton {
//     string state = "start";
//     unordered_map<string, vector<string>> table = {
//         {"start", {"start", "signed", "in_number", "end"}},
//         {"signed", {"end", "end", "in_number", "end"}},
//         {"in_number", {"end", "end", "in_number", "end"}},
//         {"end", {"end", "end", "end", "end"}}
//     };

//     int get_col(char c) {
//         if (isspace(c)) return 0;
//         if (c == '+' or c == '-') return 1;
//         if (isdigit(c)) return 2;
//         return 3;
//     }
// public:
//     int sign = 1;
//     long long ans = 0;

//     void get(char c) {
//         state = table[state][get_col(c)];
//         if (state == "in_number") {
//             ans = ans * 10 + c - '0';
//             ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
//         }
//         else if (state == "signed")
//             sign = c == '+' ? 1 : -1;
//     }
// };

// class Solution {
// public:
//     int myAtoi(string str) {
//         Automaton automaton;
//         for (char c : str)
//             automaton.get(c);
//         return automaton.sign * automaton.ans;
//     }
// };

// O(n)
class Solution {
public:
    int myAtoi(string str) {
        int i = 0, flag = 1;
        long long ans = 0;

        while (i < str.length() && isspace(str[i])) i++;
        if (i >= str.length()) return 0;

        if (str[i] == '-') flag = -1;
        else if (str[i] == '+') flag = 1;
        else if (isdigit(str[i])) ans += str[i] - '0';
        else return 0;

        i++;
        while (i < str.length() && isdigit(str[i])) {
            if (ans > INT_MAX) return (flag == 1) ? INT_MAX : INT_MIN;
            ans *= 10;
            ans += str[i] - '0';
            i++;
        }
        if ((int)ans == ans)
            return flag * ans;
        else return (flag == 1) ? INT_MAX : INT_MIN;
    }
};

// Test cases
// "   -42"
// "4193 with words"
// "words and 987"
// "-91283472332"
// @lc code=end

