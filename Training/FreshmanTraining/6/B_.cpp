#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 405;
int g[maxn][maxn];
int dijkstra(int u, int n)
{
    int d[maxn];
    bool visit[maxn];
    memset(d, 0x3f, sizeof(d));
    memset(visit, 0, sizeof(visit));

    d[u] = 0;
    for (int k = 0; k < n; ++k)
    {
        int x = -1, mind = INF;
        for (int i = 1; i <= n; ++i)
            if (!visit[i] && d[i] < mind)
            {
                mind = d[i];
                x = i;
            }
        if (x == -1)
            break;
        visit[x] = true;
        for (int i = 1; i <= n; ++i)
            if (!visit[i])
                d[i] = min(d[i], d[x] + g[x][i]);
    }
    return d[n];
}

int main(void)
{
    int n, m, bp, ep;
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g)); //pay attention
    for (int i = 0; i < m; ++i)
    {
        cin >> bp >> ep;
        g[bp][ep] = g[ep][bp] = 1;
    }

    int route1 = dijkstra(1, n);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            g[i][j] = (g[i][j] == 1) ? INF : 1;

    int route2 = dijkstra(1, n);
    if (route1 >= INF || route2 >= INF)
        cout << -1 << endl;
    else
        cout << max(route1, route2) << endl;
    return 0;
}