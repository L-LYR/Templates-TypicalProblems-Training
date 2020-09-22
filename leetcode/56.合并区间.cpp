/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
// O(nlogn)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return {};
        sort(intervals.begin(), intervals.end(), [](const vector<int> &l, const vector<int>&r) -> bool {
            if (l[0] != r[0]) return l[0] < r[0];
            else return l[1] < r[1];
        }); // O(nlogn)

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        // O(n)
        for (int i = 1; i < n; ++i) {
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

