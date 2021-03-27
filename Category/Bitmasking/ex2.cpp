// Time: 03/19/21
// Author: HammerLi
// Tags: [DP][Bitmasking]
// Title: 炮兵阵地
#include <bits/stdc++.h>
using namespace std;
const int maxn = 101;
const int lim = 1 << 11;

char c;
int n, m, ans;
int g[maxn];
int f[maxn][lim][lim];
unordered_map<int, int> states;

auto dfs(int cur_state, int cur_cnt, int cur_loc) -> void {
    if (cur_loc >= m) {
        states[cur_state] = cur_cnt;
        return;
    }
    dfs(cur_state, cur_cnt, cur_loc + 1);
    dfs(cur_state | (1 << cur_loc), cur_cnt + 1, cur_loc + 3);
}

auto main() -> int {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c;
            if (c == 'H') {
                g[i] |= 1 << j;
            }
        }
    }

    dfs(0, 0, 0);

    for (const auto &s : states) {
        if (s.first & g[1])
            continue;
        f[1][s.first][0] = s.second;
    }

    for (const auto &s1 : states) {
        if (s1.first & g[2])
            continue;
        for (const auto &s2 : states) {
            if (s2.first & g[1])
                continue;
            f[2][s1.first][s2.first] = max(f[2][s1.first][s2.first], f[1][s2.first][0] + s1.second);
        }
    }

    for (int i = 3; i <= n; ++i) {
        for (const auto &s1 : states) {
            if (s1.first & g[i])
                continue;
            for (const auto &s2 : states) {
                if (s2.first & g[i - 1])
                    continue;
                if (s1.first & s2.first)
                    continue;
                for (const auto &s3 : states) {
                    if (s3.first & g[i - 2])
                        continue;
                    if (s1.first & s3.first)
                        continue;
                    if (s2.first & s3.first)
                        continue;
                    f[i][s1.first][s2.first] = max(f[i][s1.first][s2.first], f[i - 1][s2.first][s3.first] + s1.second);
                }
            }
        }
    }

    for (const auto &s1 : states) {
        if (s1.first & g[n])
            continue;
        for (const auto &s2 : states) {
            if (s2.first & g[n - 1])
                continue;
            if (s1.first & s2.first)
                continue;
            ans = max(f[n][s1.first][s2.first], ans);
        }
    }

    cout << ans << endl;
    return 0;
}