#include <bits/stdc++.h>
using namespace std;

// divide the input into two parts
long long dp1[(1 << 20) + 1];
long long dp2[(1 << 20) + 1];

auto main() -> int {
    auto n = 0;
    auto t = 0ll;
    cin >> n >> t;

    auto a = vector<long long>(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    auto m = n / 2;
    auto lim1 = 1 << m;
    for (int s = 1; s < lim1; ++s) {
        for (int i = 0; i < m; ++i) {
            if (s & (1 << i)) {
                if (dp1[s ^ (1 << i)] + a[i] <= t)
                    dp1[s] = max(dp1[s], dp1[s ^ (1 << i)] + a[i]);
            }
        }
    }

    auto lim2 = 1 << (n - m);
    for (int s = 1; s < lim2; ++s) {
        for (int i = m; i < n; ++i) {
            auto j = i - m;
            if (s & (1 << j)) {
                if (dp1[s ^ (1 << j)] + a[i] <= t)
                    dp2[s] = max(dp2[s], dp2[s ^ (1 << j)] + a[i]);
            }
        }
    }
    auto ans = 0ll;
    sort(dp2, dp2 + lim2);
    for (int s = 0; s < lim1; ++s) {
        auto r = *(upper_bound(dp2, dp2 + lim2, t - dp1[s]) - 1);
        if (r + dp1[s] <= t) ans = max(ans, r + dp1[s]);
    }
    cout << ans << endl;
    return 0;
}