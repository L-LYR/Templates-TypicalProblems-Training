#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;
using ll = long long;
char s1[maxn], s2[maxn];

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%s%s", s1, s2);
    ll ans = 0;
    int len = min(n, m);
    for (int i = 0; i < len; ++i)
    {
        if (s1[i] != s2[i])
            ans++;
    }
    ans += abs(m - n);
    printf("%lld", ans);

    return 0;
}