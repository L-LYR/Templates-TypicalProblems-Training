#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

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
ll inv(ll x, ll mod)
{
    return fastPow(x, mod - 2, mod);
}
ll C(ll n, ll m, ll mod)
{
    if (n < m)
        return 0;
    ll up = 1, down = 1;
    for (int i = n - m + 1; i <= n; ++i)
        up = up * i % mod;
    for (int i = 1; i <= m; ++i)
        down = down * i % mod;
    return up * inv(down, mod) % mod;
}
ll Lucas(ll n, ll m, ll mod)
{
    if (m == 0)
        return 1;
    else
        return Lucas(n / mod, m / mod, mod) * C(n % mod, m % mod, mod) % mod;
}
int main(void)
{
    ll n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);
    printf("%lld\n", ((fastPow(2, n, mod) - 1ll - Lucas(n, a, mod) + mod) % mod - Lucas(n, b, mod) + mod) % mod);
    return 0;
}