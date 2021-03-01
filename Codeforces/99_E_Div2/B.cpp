#include <bits/stdc++.h>
using namespace std;
#define p first
#define c second

auto main() -> int {
    int t = 0;
    cin >> t;
    auto tab = vector<int>(1500);
    for (int i = 0; i < 1500; ++i) tab[i] = (i + 1) * i / 2;
    while (t-- > 0) {
        int n = 0;
        cin >> n;
        int idx = upper_bound(tab.begin(), tab.end(), n) - tab.begin();
        if (tab[idx - 1] == n) {
            cout << idx - 1 << endl;
        } else if (tab[idx] - n == 1) {
            cout << idx + 1 << endl;
        } else {
            cout << idx << endl;
        }
    }
    return 0;
}