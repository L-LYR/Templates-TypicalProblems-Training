#include <bits/stdc++.h>
using namespace std;
#define l first
#define r second

auto cmp = [](const pair<int, int>& x, const pair<int, int>& y) {
    return x.l + x.r < y.l + y.r;
};

auto main(void) -> int {
    auto n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    auto seq = vector<pair<int, int>>(m);
    for (auto i = 0; i < m; ++i) {
        cin >> seq[i].l >> seq[i].r;
        seq[i].l--;  // (l-r) the number of tasks
    }
    sort(seq.begin(), seq.end(), cmp);
    auto sedit = vector<int>(m + 1, 0);
    for (auto i = 0; i < n - k + 1; ++i) {
        auto cur = 0;
        for (auto j = m - 1; j >= 0; --j) {
            // backwards
            // calculate the number of tasks
            // covered in the current editorial (i, i + k]
            cur += max(0, min(i + k, seq[j].r) - max(i, seq[j].l));
            sedit[j] = max(cur, sedit[j]);
        }
    }
    auto ans = sedit[0];
    for (auto i = 0; i < n - k + 1; ++i) {
        auto cur = 0;
        for (auto j = 0; j < m; ++j) {
            // forwards
            // the same as the above
            cur += max(0, min(i + k, seq[j].r) - max(i, seq[j].l));
            ans = max(ans, cur + sedit[j + 1]);
        }
    }
    cout << ans << endl;
    return 0;
}