/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start

// merge or traverse
// O(m + n) TLE

// divide & conquer
// O(log(m + n))

class Solution
{
public:
    // Find the k-th element of two sorted arrays.
    // Suppose two arrays called A and B. We need to find index i
    // of A and index j of B which satisfy conditions below:
    //      1. i + j = k
    //      2. A[i - 1] <= B[j]
    //      3. B[j - 1] <= A[i]
    // Use bisection mothod to get i. We need to know the range of i.
    // We already know that 0 <= i <= A.length
    // and 0 <= j <= B.length while j = k - i.
    // So we have 0 <= k - i <= B.length, then we get
    // max(0, k - B.length) <= i <= min(k, A.length)
    // After we find the two indexes, the k-th elment is
    // the maximum of A[i - 1] and B[j - 1].
    // But if i = 0, then the k-th element should be B[j - 1].
    // Also if j = 0 when i = k, then the k-th element should be A[i - 1].
    int findKthElem(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int l = max(0, int(k - nums2.size())), r = min(k, int(nums1.size()));
        while (l < r)
        {
            int m = (l + r) / 2;
            if (nums2[k - m - 1] > nums1[m])
                l = m + 1;
            else
                r = m;
        }

        if (l == 0)
            return nums2[k - l - 1];
        else if (l == k)
            return nums1[l - 1];
        else
            return max(nums1[l - 1], nums2[k - l - 1]);
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size() + nums2.size();
        int m = findKthElem(nums1, nums2, n / 2 + 1);
        if (n % 2)
            return m;
        else
            return (findKthElem(nums1, nums2, n / 2) + m) / 2.0;
    }
};
// @lc code=end
