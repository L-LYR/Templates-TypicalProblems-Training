#include <bits/stdc++.h>
using namespace std;
// TSP
// DP with bitmasking
// TODO: add comments and review
const int maxn = 17;
const int inf = 0x3f3f3f3f;

struct Point {
    int x, y, z;
};

inline int cost(const Point& a, const Point& b) {
    return abs(a.x - b.x) + abs(a.y - b.y) + max(0, b.z - a.z);
}

Point p[maxn];
int c[maxn][maxn];
int dp[1 << maxn][maxn];

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].z;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = cost(p[i], p[j]);
        }
    }

    int lim = 1 << n;
    int ans = inf;
    for (int i = 0; i < lim; ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = inf;
        }
    }
    dp[1][0] = 0;
    for (int i = 1; i < lim; ++i) {
        for (int j = 1; j < n; ++j) {
            if (i & (1 << j) || !(i & 1)) continue;
            for (int k = 0; k < n; ++k) {
                if (i & (1 << k)) {
                    dp[(1 << j) | i][j] =
                        min(dp[(1 << j) | i][j], dp[i][k] + c[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        ans = min(dp[lim - 1][i] + c[i][0], ans);
    }

    cout << ans << endl;

    return 0;
}