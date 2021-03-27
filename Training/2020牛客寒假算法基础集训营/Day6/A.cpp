#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
ll a[maxn], b[maxn];
int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &b[i]);
    sort(a + 1, a + n + 1, greater<ll>());
    sort(b + 1, b + n + 1, greater<ll>());
    for (int i = 1; i <= k; ++i)
        a[i] += b[k - i + 1];
    sort(a + 1, a + k + 1, greater<ll>());
    printf("%lld\n", a[k]);

    return 0;
}