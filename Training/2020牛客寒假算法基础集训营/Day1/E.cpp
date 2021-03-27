#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;
int factorNumber(ll n)
{
    int cnt = 2;
    ll sqrt_n = sqrt(n);
    for (ll i = 2; i <= sqrt_n; ++i)
    {
        if (n % i == 0)
        {
            if (i == sqrt_n && n / i == i)
                cnt++;
            else
                cnt += 2;
        }
    }
    return cnt;
}

int main(void)
{
    ll n;
    scanf("%lld", &n);
    int cnt = 0;
    do
    {
        cnt++;
        n = factorNumber(n);
    } while (n != 2);
    printf("%d\n", cnt);
    return 0;
}