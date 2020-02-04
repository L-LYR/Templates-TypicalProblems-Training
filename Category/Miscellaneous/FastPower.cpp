// luogu P1226: https://www.luogu.com.cn/problem/P1226
// Fast Power (with module)
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
using ll = long long;

ll fastPower(ll base, ll expo, ll mod) // calculate base^expo
{
    ll ans = 1;
    while (expo > 0)
    {
        if (expo & 1)
        {
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        expo >>= 1;
    }
    return ans % mod; // important
}

int main(void)
{
    ll b, p, k;
    scanf("%lld %lld %lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld\n", b, p, k, fastPower(b, p, k));
    return 0;
}