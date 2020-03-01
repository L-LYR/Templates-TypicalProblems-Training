#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;
const int maxn = 85;
ll f[maxn];
int main(void)
{
    f[0] = 0;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= 82; ++i)
        f[i] = f[i - 1] + f[i - 2];

    int T;
    scanf("%d", &T);
    while (T-- > 0)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", f[n + 1] + f[n]);
    }

    return 0;
}