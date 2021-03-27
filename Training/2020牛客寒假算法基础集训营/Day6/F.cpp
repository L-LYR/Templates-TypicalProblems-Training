#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int maxn = 2005;
const int maxh = 5e5 + 5;
const ll mod = 1e9 + 7;
inline long long read(void)
{
    long long x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}
int main(void)
{
    ll ans = 0;

    ll N = read(), M = read(), H = read();
    ll wn = (N * (N + 1)) / 2, wm = (M * (M + 1)) / 2;
    ll x, y, z;
    for (int i = 0; i < H; ++i)
    {
        x = read();
        y = read();
        z = read();
        ll s = z * ((y * N + wn + x * M + wm - y - x) % mod) % mod;
        ans = (ans + s) % mod;
    }

    printf("%lld\n", ans % mod);
    return 0;
}
