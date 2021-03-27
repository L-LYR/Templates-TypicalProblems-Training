#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int a[maxn], b[maxn];
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    sort(a, a + n);
    sort(b, b + n);
    ll ans = 1;
    for (int i = 0, j = 0; i < n; ++i)
    {
        while (j < n && a[j] <= b[i])
            ++j;
        ans = ans * max(0, j - i) % mod;
    }
    printf("%lld\n", (ans + mod) % mod);
    return 0;
}
