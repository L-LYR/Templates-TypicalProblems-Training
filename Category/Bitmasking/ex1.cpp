// Time: 03/19/21
// Author: HammerLi
// Tags: [DP][Bitmasking]
// Titile: SCOI2005互不侵犯
// Content:
// 在N×N的棋盘里面放K个国王，使他们互不攻击，共有多少种摆放方案。
// 国王能攻击到它上下左右，以及左上左下右上右下八个方向上附近的各一个格子，共8个格子。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
const int lim = 1 << 10;

int n, k;
map<int, int> states;
int64_t f[maxn][lim][maxn * maxn];

auto dfs(int cur_state, int cur_cnt, int cur_loc) -> void {
    if (cur_loc >= n) {
        states[cur_state] = cur_cnt;
        return;
    }
    dfs(cur_state, cur_cnt, cur_loc + 1);
    dfs(cur_state | (1 << cur_loc), cur_cnt + 1, cur_loc + 2);
}

auto main() -> int {
    cin >> n >> k;
    dfs(0, 0, 0);

    for (const auto &state : states) {
        f[1][state.first][state.second] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (const auto &s1 : states) {
            for (const auto &s2 : states) {
                if (s1.first & s2.first)
                    continue;
                if ((s1.first << 1) & s2.first)
                    continue;
                if (s1.first & (s2.first << 1))
                    continue;
                for (int p = s1.second; p <= k; ++p) {
                    f[i][s1.first][p] += f[i - 1][s2.first][p - s1.second];
                }
            }
        }
    }
    int64_t ans = 0;
    for (const auto &s : states) {
        ans += f[n][s.first][k];
    }
    cout << ans << endl;
    return 0;
}