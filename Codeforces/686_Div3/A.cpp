#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto t = 0;
    cin >> t;
    while (t-- > 0) {
        auto n = 0;
        cin >> n;
        for (int i = 2; i <= n; ++i) cout << i << " ";
        cout << 1 << endl;
    }
    return 0;
}