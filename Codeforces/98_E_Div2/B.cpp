#include <bits/stdc++.h>
using namespace std;

auto main(void) -> int {
    auto t = 0;
    cin >> t;
    while (t-- > 0) {
        auto n = 0;
        cin >> n;
        auto sum = 0ll, cur = 0ll, mx = 0ll;
        for (auto i = 0; i < n; ++i) {
            cin >> cur;
            sum += cur;
            mx = max(cur, mx);
        }
        mx = max((sum + n - 2) / (n - 1), mx);
        cout << (n - 1) * mx - sum << endl;
    }

    return 0;
}