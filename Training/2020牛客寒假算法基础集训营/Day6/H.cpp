#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxn = 4e5 + 5;
// relative move
int n, m, s, t;
int a, b, c, d;
int w[maxn], v[maxn];
ll ans;
int find(int f)
{
    int l = -1, r = n;
    while (l < r - 1)
    {
        int m = (l + r) >> 1;
        if (f ? v[m] < s : w[m] <= t)
            l = m;
        else
            r = m;
    }
    return f ? r : n - r;
}
int main(void)
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        w[i] = a - b; // diagonal
        v[i] = c - d;
    }
    sort(w, w + n);
    sort(v, v + n);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        s = a - b;
        t = c - d;
        ans += n - find(1) - find(0);
    }
    printf("%lld\n", ans);
    return 0;
}