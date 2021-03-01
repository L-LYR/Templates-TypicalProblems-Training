#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 2;

vector<int> g[maxn];
auto deg = vector<int>(maxn);
auto cnt = vector<int>(maxn);

auto main() -> int {
    auto t = 0;
    cin >> t;
    while (t-- > 0) {
        auto n = 0, u = 0, v = 0;
        cin >> n;
        deg.resize(n + 1);
        cnt.resize(n + 1);
        for (auto i = 1; i <= n; ++i) {
            g[i].clear();
            deg[i] = 0;
            cnt[i] = 1;
        }
        for (auto i = 1; i <= n; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        for (auto i = 1; i <= n; ++i) {
            if (deg[i] == 1) {
                deg[i]--;
                for (auto v : g[i]) {
                    if (deg[v] > 0) {
                        cnt[v] += cnt[i];
                        deg[v]--;
                    }
                }
                cnt[i] = 0;
            }
        }
        auto ans = 0ll;
        for (auto i = 1; i <= n; ++i) {
            ans += cnt[i] * 1ll * (cnt[i] - 1) / 2;
            ans += cnt[i] * 1ll * (n - cnt[i]);
        }
        cout << ans << endl;
    }
    return 0;
}