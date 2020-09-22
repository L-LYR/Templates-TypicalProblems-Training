/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
// O(n)
// Find insertion location.
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0) return {newInterval};
        vector<vector<int>> ans;
        // O(n)
        int i;
        for (i = 0; i < n; ++i) {
            if (intervals[i][1] >= newInterval[0] || intervals[i][0] >= newInterval[0]) {
                break;
            } else {
                ans.push_back(intervals[i]);
            }
        }
        if (i == n) {
            ans.push_back(newInterval);
            return ans;
        }
        if (intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        for (; i < n; ++i) {
            if (ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            } else if (ans.back()[1] < intervals[i][1]) {
                ans.back()[1] = intervals[i][1];
            }
        }
        
        return ans;
    }
};
// @lc code=end

