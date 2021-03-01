#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto t = 0;
    cin >> t;
    while (t-- > 0) {
        auto n = 0ll;
        cin >> n;

        auto val = vector<pair<long long, long long>>();
        for (auto i = 2ll; i * i <= n; ++i) {
            auto cnt = 0;
            while (n % i == 0) {
                ++cnt;
                n /= i;
            }
            if (cnt > 0) val.push_back({cnt, i});
        }
        if (n > 1) val.push_back({1, n});
        sort(val.rbegin(), val.rend());
        auto ans = vector<long long>(val[0].first, val[0].second);
        for (auto i = 1; i < int(val.size()); ++i) {
            for (auto j = 0; j < val[i].first; ++j) {
                ans.back() *= val[i].second;
            }
        }
        cout << ans.size() << endl;
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}