/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
// O(n)
// This problem doesn't take the prefix zero into consideration.
class Solution {
public:
    bool isNumber(string s) {
        int i = 0, st;
        bool mInt1, mInt2;
        while (s[i] == ' ') i++;                    // skip the prefix space
        if (s[i] == '+' || s[i] == '-') i++;        // skip the prefix mark
        st = i;
        while (isdigit(s[i])) i++;                  // match a integer
        mInt1 = (st != i);                          // match is ok?
        
        if (s[i] == '.') {                          // match a dot
            i++;
            st = i;         
            while (isdigit(s[i])) i++;              // match another integer
            mInt2 = (st != i);                      // match is ok?
            if (!(mInt1 || mInt2)) return false;    // match a dot, but both sides are not integers, false
        } else if (!mInt1) return false;            // no dot, no integer, false

        if (s[i] == 'e') {                          // match a 'e'
            i++;
            if (s[i] == '+' || s[i] == '-') i++;    // skip the mark
            st = i;
            while(isdigit(s[i])) i++;               // match a integer for e
            if (st == i) return false;              // no match, false
        }
        while (s[i] == ' ') i++;                    // match the rest for all space
        return i == s.length();                     // not the end, false
    }
};
// "0"
// " 0.1 "
// "abc"
// "1 a"
// "2e10"
// " -90e3   "
// " 1e"
// "e3"
// " 6e-1"
// " 99e2.5 "
// "53.5e93"
// " --6 "
// "-+3"
// "95a54e53"
// @lc code=end

