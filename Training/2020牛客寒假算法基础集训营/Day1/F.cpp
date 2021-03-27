#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
using ll = long long;
const int maxn = 100005;
int f[maxn], cnt[maxn];
vector<int> g[maxn];
char str[maxn];

void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        f[i] = i;
        cnt[i] = 1;
    }
}
int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}
void merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y)
        return;
    if (cnt[x] > cnt[y])
        swap(x, y);
    f[x] = y;
    cnt[y] += cnt[x];
}
int main(void)
{
    int n;
    scanf("%d", &n);
    scanf("%s", str + 1);
    init(n);
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        if (str[u] == 'W' && str[v] == 'W')
            merge(u, v);
    }
    ll ans = 0;
    for (int u = 1; u <= n; ++u)
    {
        if (str[u] == 'W')
            continue;
        ll case1 = 0, case2 = 0;
        for (auto v : g[u])
        {
            if (str[v] == 'B')
                continue;
            case2 += cnt[find(v)] * case1;
            case1 += cnt[find(v)];
        }
        ans += case1 + case2;
    }
    printf("%lld\n", ans);
    return 0;
}