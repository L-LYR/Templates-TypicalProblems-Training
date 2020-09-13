/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
// O(log(n))
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int l = greaterEqualThan(nums, target, 0, nums.size());
        int r = greaterThan(nums, target, 0, nums.size());
        if (l == nums.size() && r == nums.size()) return {-1, -1};
        else if (l == r) return {-1, -1};
        else return {l, r - 1};
    }
    // C++ standard library version
    // [l, r)
    int greaterEqualThan(vector<int>& nums, int target, int l, int r) {
        int dis = r - l, i, step;
        while (dis > 0) {
            i = l;
            step = dis / 2;
            i += step;
            if (nums[i] >= target) { // control condition
                dis = step;
            } else {
                l = ++i;
                dis -= step + 1;
            }
        }
        return l;
    }
    int greaterThan(vector<int>& nums, int target, int l, int r) {
        int dis = r - l, i, step;
        while (dis > 0) {
            i = l;
            step = dis / 2;
            i += step;
            if (nums[i] > target) {
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

