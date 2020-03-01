#include <iostream>
#include <cstring>
#include <map>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int a[maxn], pre[maxn];
int main(void)
{
    int n;
    ll ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    pre[0] = 0; // pre[i] = a[0]^a[1]^...^a[i-1] = [0,i)
    for (int i = 0; i < n; ++i)
    {
        pre[i + 1] = pre[i] ^ a[i];
        // printf("%d ", pre[i + 1]);
    }
    // printf("\n");
    // for (int i = 0; i < n; ++i)
    //     for (int j = i + 1; j <= n; ++j)
    //         if ((pre[i] ^ pre[j]) == 0)
    //         {
    //             printf("%d %d\n", i, j);
    //             ans++;
    //         }
    map<int, int> m;
    for (int i = 0; i <= n; ++i)
        m[pre[i]]++;
    for (auto k : m)
    {
        ll t = k.second;
        if (t >= 2)
            ans += t * (t - 1) / 2;
    }
    printf("%lld\n", ans);
    return 0;
}