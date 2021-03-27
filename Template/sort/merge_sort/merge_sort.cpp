#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::is_sorted;
using std::vector;
using std::min;

const int max_length = 1e2;
const int max_value = 1e3;

auto __merge(vector<int>& v, int lo, int mid, int hi) -> void {
    // [lo, mid]
    vector<int> leftVec(v.begin() + lo, v.begin() + mid + 1);
    // (mid, hi]
    vector<int> rightVec(v.begin() + mid + 1, v.begin() + hi + 1);

    // merge two sorted arrays
    int idxLeft = 0, idxRight = 0, i = lo;
    while (idxLeft < leftVec.size() && idxRight < rightVec.size()) {
        if (leftVec[idxLeft] < rightVec[idxRight])
            v[i++] = leftVec[idxLeft++];
        else
            v[i++] = rightVec[idxRight++];
    }

    while (idxLeft < leftVec.size()) v[i++] = leftVec[idxLeft++];

    while (idxRight < rightVec.size()) v[i++] = rightVec[idxRight++];
}

auto __merge_sort_recursive(vector<int>& v, int lo, int hi) -> void {
    if (lo >= hi) return;
    int mid = (hi - lo) / 2 + lo;
    __merge_sort_recursive(v, lo, mid);
    __merge_sort_recursive(v, mid + 1, hi);
    __merge(v, lo, mid, hi);
}

auto __merge_sort_nonrecursive(vector<int>& v) -> void {
    // tmp array
    vector<int> tmp(v.size());
    int len = v.size();
    for (int seg_len = 1; seg_len < len; seg_len += seg_len) {
        // divide segments
        int start = 0;
        // for each segment
        while (start < len) {
            int lo = start;
            int mid = min(lo + seg_len, len);
            int hi = min(lo + seg_len * 2, len);
            start = hi;  // next start

            // merge two sorted arrays
            int i = lo, j = mid, k = lo;
            while (i < mid && j < hi) {
                if (v[i] < v[j])
                    tmp[k++] = v[i++];
                else
                    tmp[k++] = v[j++];
            }
            while (i < mid) tmp[k++] = v[i++];
            while (j < hi) tmp[k++] = v[j++];
        }
        v.swap(tmp);
    }
}

auto merge_sort(vector<int>& v) -> void {
    if (!v.empty()) {
        // __merge_sort_recursive(v, 0, v.size() - 1);
        __merge_sort_nonrecursive(v);
    }
}

auto main(void) -> int {
    vector<int> rand_vec;

    srand(time(0));

    for (int i = 0; i < max_length; ++i) {
        rand_vec.push_back(rand() % max_value + 1);
    }

    merge_sort(rand_vec);

    cout << is_sorted(rand_vec.begin(), rand_vec.end()) << endl;

    return 0;
}