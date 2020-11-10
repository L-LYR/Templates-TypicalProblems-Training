#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 405;

ll a[maxn], sum[maxn];
ll dp[maxn][maxn];

int main(void) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    // prefix sum
    for (int i = 1; i <= n; ++i)
        sum[i] = sum[i - 1] + a[i];

    memset(dp, 0, sizeof(dp));
    for (int l = 2; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            ll cur = inf;
            for (int k = i; k < j; ++k) {
                cur = min(cur,
                          dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
            }
            dp[i][j] = cur;
        }
    }
    cout << dp[1][n] << endl;

    return 0;
}