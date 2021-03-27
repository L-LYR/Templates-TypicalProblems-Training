#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int max_length = 1e2;
const int max_value = 1e3;

auto __make_heap(vector<int>& v, int lo, int hi) -> void {
    // [lo, hi]
    // lo is the parent's index, hi is the right bound
    int i = 2 * lo + 1;  // left child
    while (i <= hi) {
        // right child is greater than the left
        if (i < hi && v[i] < v[i + 1]) i++;
        // parent is greater than the child
        // done.
        if (v[lo] > v[i]) break;
        // child is greater than the parent
        swap(v[lo], v[i]);
        lo = i;         // current child is then next parent
        i = i * 2 + 1;  // next left child
    }
}

auto __heap_sort(vector<int>& v) -> void {
    // heapify from the last parent node
    for (int i = v.size() / 2 - 1; i >= 0; i--) {
        __make_heap(v, i, v.size() - 1);
    }
    // heapify from the last node
    for (int i = v.size() - 1; i > 0; i--) {
        // the first node is always the max/min one
        swap(v[i], v[0]);
        // heapify the rest.
        __make_heap(v, 0, i - 1);
    }
}

auto heap_sort(vector<int>& v) -> void {
    if (!v.empty()) {
        __heap_sort(v);
    }
}

auto main(void) -> int {
    vector<int> rand_vec;

    srand(time(0));

    for (int i = 0; i < max_length; ++i) {
        rand_vec.push_back(rand() % max_value + 1);
    }

    heap_sort(rand_vec);

    cout << is_sorted(rand_vec.begin(), rand_vec.end()) << endl;

    return 0;
}