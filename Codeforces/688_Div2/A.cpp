#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, m;
        cin >> n >> m;
        auto l = set<int>();
        int cur;
        for (int i = 0; i < n; ++i) {
            cin >> cur;
            l.insert(cur);
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            cin >> cur;
            if (l.count(cur)) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}