#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int max_length = 5;
const int max_value = 1e3;

auto __merge_sort_count(vector<int>& nums, vector<int>& tmp, int lo, int hi, int& cnt)
    -> void {
    if (lo >= hi) {
        return;
    }
    int m = (hi - lo) / 2 + lo;
    __merge_sort_count(nums, tmp, lo, m, cnt);
    __merge_sort_count(nums, tmp, m + 1, hi, cnt);
    //  merge & count

    int i = lo, j = m + 1, k = lo;
    while (i <= m && j <= hi) {
        if (nums[i] > nums[j]) {
            cnt += (hi - j + 1);
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
        }
    }
    while (i <= m) tmp[k++] = nums[i++];
    while (j <= hi) tmp[k++] = nums[j++];

    copy(next(tmp.begin(), lo), next(tmp.begin(), hi + 1),
              next(nums.begin(), lo));
}

auto count_reverse_pairs(vector<int>& nums) -> int {
    if (nums.empty()) return 0;
    int cnt = 0;
    vector<int> tmp(nums.size());
    __merge_sort_count(nums, tmp, 0, nums.size() - 1, cnt);
    return cnt;
}

auto main(void) -> int {
    vector<int> rand_vec;

    srand(time(0));

    for (int i = 0; i < max_length; ++i) {
        rand_vec.push_back(rand() % max_value + 1);
        cout << rand_vec[i] << " ";
    }

    cout << count_reverse_pairs(rand_vec) << endl;

    return 0;
}