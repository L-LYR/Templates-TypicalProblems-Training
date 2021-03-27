#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;
const int maxn = 3e6 + 5;
const int mod = 998244353;

ll fac[maxn], inv[maxn];
ll p3[maxn], p2[maxn];
ll n, m;

ll fastPow(ll base, ll expo)
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

void init()
{
    fac[0] = p2[0] = p3[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fac[i] = fac[i - 1] * i % mod;
        p2[i] = p2[i - 1] * 2 % mod;
        p3[i] = p3[i - 1] * 3 % mod;
    }
    inv[n] = fastPow(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; --i)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}

ll C(ll n, ll m)
{
    if (n < 0 || m < 0 || n - m < 0)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

ll f(int i, int j)
{
    if (i < 0 || j < 0 || i - j < 0)
        return 0;
    return C(i, j) * p2[j] % mod * p3[i - j] % mod;
}
int main(void)
{
    scanf("%d%d", &n, &m);
    init();
    ll ans = 0, cur = 0, l, r, pl = 0, pr = 0;
    for (int i = n; i >= 0; --i)
    {
        l = max((n - m - i + 1) / 2, 0ll);
        r = min((n + m - i) / 2, n - i);

        if (i == n)
            cur = 1;
        else
        {
            for (int j = pl; j < l; ++j)
                cur = (cur - f(n - i, j) + mod) % mod;

            for (int j = l; j < pl; ++j)
                cur = (cur + f(n - i, j)) % mod;

            for (int j = pr + 1; j <= r; ++j)
                cur = (cur + f(n - i, j)) % mod;

            for (int j = r + 1; j <= pr; ++j)
                cur = (cur - f(n - i, j) + mod) % mod;
        }

        ans = (ans + cur * C(n, i) % mod) % mod;

        pl = l;
        pr = r;

        cur = cur * 5 % mod;
        cur = (cur + 2 * f(n - i, pl - 1) % mod) % mod;
        cur = (cur + 3 * f(n - i, pr + 1) % mod) % mod;
        pr++;
    }
    printf("%lld\n", ans);

    return 0;
}