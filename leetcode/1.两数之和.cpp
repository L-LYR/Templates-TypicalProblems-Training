/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start

// Brute Force!!!
// O(n^2)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            int component = target - nums[i];
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] == component)
                    return {j, i};
            }
        }
        return {};
    }
};

// Use Hash to help search for component
// O(n)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int len = nums.size();
        map<int, int> numsIdx;
        for (int i = 0; i < len; i++)
        {
            int component = target - nums[i];
            auto j = numsIdx.find(component);
            if (j != numsIdx.end())
                return {j->second, i};
            numsIdx.insert(make_pair(nums[i], i));
        }
        return {};
    }
};

// @lc code=end

