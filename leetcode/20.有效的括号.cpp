/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
// O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<char> cs;
        int n = s.length();
        // using a stack is enough
        for (int i = 0; i < n; ++i) {
            switch(s[i]) {
            case '{' :
            case '[' :
            case '(' :
                cs.push(s[i]);
                break;
            case ')' :
                // pay attention to the conditions
                if (cs.empty() || cs.top() != '(') return false;
                cs.pop();
                break;
            case ']' :
                if (cs.empty() || cs.top() != '[') return false;
                cs.pop();
                break;
            case '}' :
                if (cs.empty() || cs.top() != '{') return false;
                cs.pop();
                break;
            }
        }
        return cs.empty();
    }
};
// @lc code=end

