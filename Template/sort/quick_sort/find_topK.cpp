#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int max_length = 10;
const int max_value = 1e3;

auto __topK_of(vector<int>& v, int lo, int hi, int k) -> int {
    int i = lo, j = hi;
    int key = v[lo];
    while (i < j) {
        while (i < j && v[j] <= key) j--;
        if (i < j) v[i++] = v[j];
        while (i < j && v[i] >= key) i++;
        if (i < j) v[j--] = v[i];
    }
    v[i] = key;
    if (i == k) return v[i];
    if (i > k) return __topK_of(v, lo, i - 1, k);
    return __topK_of(v, i + 1, hi, k);
}

auto topK_of(vector<int>& v, int k) -> int {
    if (v.empty() || k < 1 || k > v.size()) return 0;
    return __topK_of(v, 0, v.size() - 1, k - 1);
}

auto main(void) -> int {
    vector<int> rand_vec;

    srand(time(0));

    for (int i = 0; i < max_length; ++i) {
        rand_vec.push_back(rand() % max_value + 1);
        cout << rand_vec[i] << " ";
    }
    cout << endl;

    cout << topK_of(rand_vec, 1) << endl;

    return 0;
}