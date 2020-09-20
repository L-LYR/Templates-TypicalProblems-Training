#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

ll mod = 1e9 + 7;

ll dp[1000];

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
ll inv(ll x)
{
    return fastPow(x, mod - 2);
}
ll C(ll n, ll m)
{
    if (n < m)
        return 0;
    ll up = 1, down = 1;
    for (int i = n - m + 1; i <= n; ++i)
        up = up * i % mod;
    for (int i = 1; i <= m; ++i)
        down = down * i % mod;
    return up * inv(down) % mod;
}

ll Lucas(ll n, ll m)
{
    if (m == 0)
        return 1;
    else
        return Lucas(n / mod, m / mod) * C(n % mod, m % mod) % mod;
}

int main(void)
{
    ll s;
    cin >> s;
    if (s < 3)
    {
        cout << 0 << endl;
        return 0;
    }
    ll i = 1;
    ll r = s - 3 * i;
    while (r >= 0)
    {
        dp[i] = Lucas(r + i - 1, r);
        i++;
        r = s - 3 * i;
    }
    ll ans = 0;
    for (int j = 1; j < i; ++j)
        ans = (ans + dp[j]) % mod;
    cout << ans << endl;
    return 0;
}