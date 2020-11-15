#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2005;
const ll mod = 1e9 + 7;
char g[maxn][maxn];
ll dp[maxn][maxn];
ll X[maxn][maxn], Y[maxn][maxn], Z[maxn][maxn];
int h, w;
int main(void) {
    cin >> h >> w;
    for (int i = 0; i < h; ++i)
        cin >> g[i];
    dp[0][0] = 1;
    for (int i = 1; i < w; ++i) {
        if (g[0][i] == '#') continue;
        dp[0][i] = X[0][i] = (X[0][i - 1] + dp[0][i - 1]) % mod;
    }
    for (int i = 1; i < h; ++i) {
        if (g[i][0] == '#') continue;
        dp[i][0] = Y[i][0] = (Y[i - 1][0] + dp[i - 1][0]) % mod;
    }

    for (int i = 1; i < h; ++i) {
        for (int j = 1; j < w; ++j) {
            if (g[i][j] == '#') continue;
            X[i][j] = (X[i][j - 1] + dp[i][j - 1]) % mod;
            Y[i][j] = (Y[i - 1][j] + dp[i - 1][j]) % mod;
            Z[i][j] = (Z[i - 1][j - 1] + dp[i - 1][j - 1]) % mod;
            dp[i][j] = (X[i][j] + Y[i][j] + Z[i][j]) % mod;
        }
    }
    cout << dp[h - 1][w - 1] << endl;
    return 0;
}