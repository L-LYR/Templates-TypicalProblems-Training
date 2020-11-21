#include <bits/stdc++.h>
using namespace std;
const auto maxn = int{1e5 + 5};
auto main(void) -> int {
    auto t = 0;
    cin >> t;
    auto a = vector<long long>();
    a.resize(maxn);
    while (t-- > 0) {
        auto n = 0, k = 0;
        cin >> n >> k;
        auto sz = n * k + 1;
        for (auto i = 1; i < sz; ++i)
            cin >> a[i];
        // To get the maximum possible sum, we need to get
        // all the maximum possible medians of each group.
        // Because the size of each group is fixed, so we can
        // calculate the location of each median, m = (n + 1) / 2.
        // And then we fill in the lower positions with smaller
        // numbers whose index is in range [1, (m - 1) * k].
        // The rest numbers will be placed in the higher positions.
        // By using the following greedy strategy, we can get the answer:
        // fill in the higher position in snake-like sequence.
        // For example,
        // 3 4
        // 3 11 12 22 33 35 38 67 69 71 94 99
        // G1: 3  33 35
        // G2: 11 38 67
        // G3: 12 69 71
        // G4: 22 94 99
        // idx: 1  2  3
        // ans: 33 + 38 + 69 + 94 = 234
        auto m = (n + 1) / 2;
        auto base = (m - 1) * k + 1;
        auto gap = n - m + 1;
        auto ans = 0LL;
        for (auto i = base; i < sz; i += gap)
            ans += a[i];
        cout << ans << endl;
    }
    return 0;
}