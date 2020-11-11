#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;

int n;
ll a[maxn];
ll sum[maxn];
ll max_sum[maxn];

int main(void) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", a + i);

    for (int i = 1; i <= n; ++i) {
        sum[i] += sum[i - 1] + a[i];
        max_sum[i] = max(sum[i], max_sum[i - 1]);
    }

    ll ans = 0, cur = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, cur + max_sum[i]);
        cur += sum[i];
    }

    cout << ans << endl;

    return 0;
}