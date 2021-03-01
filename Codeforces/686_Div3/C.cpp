#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto t = 0;
    cin >> t;
    while (t-- > 0) {
        auto n = 0;
        cin >> n;
        auto cnt = vector<int>(n + 1, 0);
        auto idx = vector<pair<int, int>>(n + 1, pair<int, int>(0, 0));
        auto last = 0, cur = 0;
        for (auto i = 0; i < n; ++i) {
            cin >> cur;
            if (cur != last) cnt[cur]++;
            if (idx[cur].first == 0) idx[cur].first = i + 1;
            idx[cur].second = i + 1;
            last = cur;
        }
        auto mn = INT32_MAX;
        for (auto i = 0; i <= n; ++i) {
            if (cnt[i] != 0) {
                if (idx[i].first == 1) cnt[i]--;
                if (idx[i].second == n) cnt[i]--;
                mn = min(cnt[i], mn);
            }
        }
        cout << mn + 1 << endl;
    }

    return 0;
}