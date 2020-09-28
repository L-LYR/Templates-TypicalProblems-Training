/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
// O(n^2)
class Solution {
   public:
    string simplifyPath(string path) {
        stack<string> ss;
        int st = 0, ne;
        while (st < path.length()) {
            ne = path.find('/', st + 1);
            string t;
            if (ne == string::npos) {
                t = path.substr(st + 1);
                st = path.length();
            } else {
                t = path.substr(st + 1, ne - st - 1);
                st = ne;
            }
            if (t == "..") {
                if (!ss.empty())
                    ss.pop();
            } else if (t != "" && t != ".")
                ss.push(t);
        }
        string ans = "";
        while (!ss.empty()) {
            if (ans == "")
                ans = ss.top();
            else
                ans = ss.top() + "/" + ans;
            ss.pop();
        }
        return "/" + ans;
    }
};
// @lc code=end
