#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxn = 205;
const int maxt = 1e5 + 5;
const int inf = 0x3f3f3f3f;
int g[maxn][maxn];
struct node
{
    int p, t;
    ll d;
} a[maxt];
ll dp[maxt];
int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= n; ++i)
        g[i][i] = 0;
    for (int i = 0, u, v; i < m; ++i)
    {
        scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = 1;
    }
    // floyd to get the min-time from u to v
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    int nk;
    scanf("%d", &nk);

    for (int i = 1, p, t, d; i <= nk; ++i)
    {
        scanf("%d%d%d", &t, &p, &d);
        a[i] = {p, t, d};
        dp[i] = -1e18; // why? Because answer may be 0.
        // When he cannot run to anywhere(m == 0), no pokeman can be caught.
        // So dp[1..nk] should be initialized with illegal value,
        // and dp[0] = 0, which will the answer.
    }

    sort(a + 1, a + nk + 1, [](const node &l, const node &r) -> bool {
        return l.t < r.t;
    });

    a[0] = {1, 0, 0}; // start point
    // bag dp
    ll ans = 0;
    for (int i = 1; i <= nk; ++i)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (i - j >= 200)
                break;
            if (g[a[i].p][a[j].p] <= a[i].t - a[j].t)
                dp[i] = max(dp[i], dp[j] + a[i].d);
        }
        ans = max(ans, dp[i]);
    }
    printf("%lld\n", ans);

    return 0;
}