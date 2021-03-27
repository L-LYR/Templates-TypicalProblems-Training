#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
int main(void)
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll plus = m + n;
    ll mul1 = (m - 1) * (n - 2);
    ll mul2 = (m - 2) * (n - 1);
    ll ans = 2 * ((((plus - 2) % mod) * ((mul1 % mod + mul2 % mod) % mod)) % mod);
    printf("%lld\n", ans % mod);
    return 0;
}