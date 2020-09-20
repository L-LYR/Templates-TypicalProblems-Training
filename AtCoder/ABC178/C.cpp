#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;

ll fp(ll b, ll n)
{
    ll ans = 1;
    while (n > 0)
    {
        if (n & 1)
            ans = ans * b % mod;
        n >>= 1;
        b = b * b % mod;
    }
    return ans % mod;
}

int main(void)
{
    ll n;
    cin >> n;
    cout << ((fp(10, n) + fp(8, n) + mod) % mod - (fp(9, n) * 2 % mod) + mod) % mod << endl;
    return 0;
}