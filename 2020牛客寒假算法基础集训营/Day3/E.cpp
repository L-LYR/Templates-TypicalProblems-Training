#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
using ll = long long;
const ll m = 1e9 + 7;
// count the occurrence frequency of digit 1 at index i from 0 to x.
ll cnt1(ll x, int i)
{
    x++;
    i++;
    ll loop = 1ll << i;
    ll half = loop >> 1;
    ll quotient = x / loop;
    ll ans = quotient * half;

    ll remainder = x % loop;
    if (remainder >= half)
        ans += remainder - half;
    return ans;
}

ll solve(ll l, ll r, int i)
{
    return cnt1(r, i) - cnt1(l - 1, i);
}

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

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T-- > 0)
    {
        ll l1, r1, l2, r2;
        scanf("%lld%lld%lld%lld", &l1, &r1, &l2, &r2);
        ll len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
        ll ans = 0;
        for (int i = 0; i < 62; ++i)
        {
            ll i1c1 = solve(l1, r1, i), i1c0 = len1 - i1c1;
            ll i2c1 = solve(l2, r2, i), i2c0 = len2 - i2c1;
            i1c1 %= m;
            i2c1 %= m;
            i1c0 %= m;
            i2c0 %= m;
            ll prod = ((i1c1 * i2c0 + i2c1 * i1c0) % m) * ((1LL << i) % m) % m;
            ans += prod;
            ans %= m;
        }
        ans = ans * fastPow(((len1 % m) * (len2 % m)) % m, m - 2, m) % m;
        printf("%lld\n", ans);
    }
    return 0;
}