/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
// monotone stack
// O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        h.insert(h.begin(), 0);
        h.push_back(0);
        stack<int> is;
        int ans = 0;
        for (int r = 0; r < h.size(); ++r) {
            while (!is.empty() && h[is.top()] > h[r]) {
                // When find the first smaller rectangle (r) at the right side
                // the top one in the stack can get the largest rectangle 
                // around it, because the second one (l) in the stack is 
                // the first smaller rectangle at the left side.
                // so we get the current area of rectangle:
                // (r - 1 - l) * h[top]
                int cur = h[is.top()];
                is.pop();
                ans = max(ans, (r - 1 - is.top()) * cur);
            }
            is.push(r);
        }
        return ans;
    }
};
// @lc code=end

