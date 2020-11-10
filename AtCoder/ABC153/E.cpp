#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1e3 + 1;
const int maxm = 2e4 + 1;
const int inf = 0x3f3f3f3f;

int n, h;
int a[maxn], b[maxn];
int dp[maxm];
int maxa;
int main(void) {
    cin >> h >> n;
    maxa = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        maxa = max(maxa, a[i]);
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= h + maxa; ++j) {
            if (j + a[i] >= h + maxa) break;
            dp[j + a[i]] = min(dp[j + a[i]], dp[j] + b[i]);
        }
    }
    int ans = inf;
    for (int i = h; i <= h + maxa; ++i) 
		ans = min(dp[i], ans);
    cout << ans << endl;
    return 0;
}
