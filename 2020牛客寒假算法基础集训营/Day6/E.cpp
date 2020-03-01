#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using ll = long long;
using namespace std;
const ll maxn = 31650; // (1e18)^(1/4)
bool vis[maxn];
vector<ll> prime, cube;
int main(void)
{
    for (ll i = 2; i < maxn; ++i)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            cube.push_back(i * i * i);
            for (ll j = i * i; j < maxn; j += i)
                vis[j] = true;
        }
    }
    int len = prime.size();

    int t;
    scanf("%d", &t);
    while (t-- > 0)
    {
        ll n;
        scanf("%lld", &n);
        ll ans = 1;
        for (int i = 0; i < len; ++i)
        {
            if (n % prime[i] == 0)
            {
                while (n % cube[i] == 0)
                {
                    n /= cube[i];
                    ans *= prime[i];
                }
                while (n % prime[i] == 0)
                    n /= prime[i];
            }
        }
        ll l = 1, r = 1e6;
        while (l <= r)
        {
            ll m = (r + l) >> 1;
            ll cm = m * m * m;
            if (cm == n)
            {
                ans *= m;
                break;
            }
            else if (cm > n)
                r = m - 1;
            else
                l = m + 1;
        }

        printf("%lld\n", ans);
    }

    return 0;
}