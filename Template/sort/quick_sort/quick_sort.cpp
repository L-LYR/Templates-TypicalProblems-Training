#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int max_length = 1e2;
const int max_value = 1e3;

auto __quick_sort_recursive(vector<int>& v, int lo, int hi) -> void {
    if (lo >= hi) return;

    // partition
    int i = lo, j = hi;
    int key = v[i];
    // 4 3 2 5 6 12 3 1
    // i              j
    // 1 3 2 5 6 12 3 1
    //   i            j
    // 1 3 2 5 6 12 3 5
    //       i      j
    // 1 3 2 3 6 12 3 5
    //         i    j
    // 1 3 2 3 6 12 6 5
    //         i  j
    // 1 3 2 3 4 12 6 5
    //         i
    //         j
    while (i < j) {
        // from the right to find a value which is less than key
        while (i < j && v[j] >= key) --j;
        if (i < j) v[i++] = v[j];  // i is pointing to a greater-than-key value
        // from the left to find a value which is greater than key
        while (i < j && v[i] <= key) ++i;
        if (i < j) v[j--] = v[i];  // j is pointing to a less-than-key value
    }
    v[i] = key;

    // left and right parts
    __quick_sort_recursive(v, lo, i - 1);
    __quick_sort_recursive(v, i + 1, hi);
}

auto quick_sort(vector<int>& v) -> void {
    if (!v.empty()) {
        __quick_sort_recursive(v, 0, v.size() - 1);
    }
}

auto main(void) -> int {
    vector<int> rand_vec;

    srand(time(0));

    for (int i = 0; i < max_length; ++i) {
        rand_vec.push_back(rand() % max_value + 1);
    }

    quick_sort(rand_vec);

    cout << is_sorted(rand_vec.begin(), rand_vec.end()) << endl;

    return 0;
}