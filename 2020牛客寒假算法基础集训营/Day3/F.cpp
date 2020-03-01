#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int l[maxn], sum[maxn];

int main(void)
{
    int n;
    scanf("%d", &n);
    getchar();
    int c, tot = 0;
    for (int i = 0; i < n; ++i)
    {
        c = getchar() - '0';
        if (c == 1)
            l[tot++] = i;
    }
    n = tot - 1;
    for (int i = n; i >= 0; --i)
        l[i] -= l[0];
    for (int i = n; i >= 0; --i)
        sum[i] = (sum[i + 1] + l[i]) % mod;
    ll ans = 0;
    for (int i = 0; i <= n; ++i)
        ans = ((ans + sum[i + 1]) % mod - ((n - i) * l[i]) % mod) % mod;
    printf("%d\n", ans % mod);
    return 0;
}