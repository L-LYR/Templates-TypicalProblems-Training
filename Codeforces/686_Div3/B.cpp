#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto t = 0;
    cin >> t;
    while (t-- > 0) {
        auto cnt = map<int, int>();
        auto n = 0;
        cin >> n;
        auto seq = vector<int>(n);
        for (auto i = 0; i < n; ++i) {
            cin >> seq[i];
            cnt[seq[i]]++;
        }
        auto mn = INT32_MAX, ans = -1;
        for (auto i = 0; i < n; ++i) {
            if (cnt[seq[i]] == 1 && seq[i] < mn) {
                mn = seq[i];
                ans = i + 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}