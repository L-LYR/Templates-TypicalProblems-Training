#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;
ll f[maxn], inv[maxn];
ll fastPow(ll base, ll expo, ll mod)
{
    ll ans = 1;
    while (expo > 0)
    {
        if (expo & 1)
            ans = ans * base % mod;
        base = base * base % mod;
        expo >>= 1;
    }
    return ans % mod;
}
void init(int n)
{
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        f[i] = f[i - 1] * i % mod;
    inv[n] = fastPow(f[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; --i)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
ll C(ll n, ll m)
{
    if (n < m)
        return 0;
    else
        return f[n] * inv[m] % mod * inv[n - m] % mod;
}
int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    ll ans = 0;
    init(n);
    for (int i = 0; i <= min(n - 1, k); ++i)
    {
        // printf("%d %d\n", C(n, i), C(n + i - 1, i));
        ans = (ans + C(n, i) * C(n - 1, i) % mod) % mod;
    }
    printf("%lld\n", ans);

    return 0;
}