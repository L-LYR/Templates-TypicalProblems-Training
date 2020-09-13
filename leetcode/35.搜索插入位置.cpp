/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
// O(log(n))
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return greaterEqualThan(nums, target, 0, nums.size());
    }

    // binary search
    // [l, r)
    int greaterEqualThan(vector<int>& nums, int target, int l, int r) {
        int dis = r - l;
        int i, step;

        while (dis > 0) {
            i = l;
            step = dis / 2;
            i += step;
            if (nums[i] >= target) {
                dis = step;
            } else {
                l = ++i;
                dis -= step + 1;
            }
        }
        return l;
    }
};
// @lc code=end

