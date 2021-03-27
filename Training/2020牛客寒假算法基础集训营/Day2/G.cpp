#include <iostream>

using namespace std;
using ll = long long;
const ll m = 1e9 + 9;
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
    return (ans % mod);
}

int main(void)
{
    int T;
    ll a, b, c, d, e, f, g, l;
    scanf("%d", &T);
    while (T-- > 0)
    {
        scanf("%lld %lld %lld %lld %lld %lld %lld",
              &a, &b, &c, &d, &e, &f, &g);
        l = fastPow(a, d, m) + fastPow(b, e, m) + fastPow(c, f, m);
        if (l % m == g % m)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}