#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, target;
    cin >> n >> target;
    vector<int> sums(n + 1);
    sums[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> sums[i];
        sums[i] += sums[i - 1];
    }
    int actual = 1e9 + 7;
    for (int l = 0; l < n; ++l) {
        auto r = lower_bound(sums.begin() + l + 1,
                             sums.end(), target + sums[l]);
        if (r == sums.end()) continue;
        int cur = *r - sums[l];
        if (cur == target) {
            actual = target;
            break;
        } else {
            actual = min(actual, cur);
        }
    }
    for (int l = 0; l < n; ++l) {
        auto r = lower_bound(sums.begin() + l + 1,
                             sums.end(), actual + sums[l]);
        if (*r - sums[l] == actual) {
            cout << l + 1 << "-" << r - sums.begin() << endl;
        }
    }

    return 0;
}