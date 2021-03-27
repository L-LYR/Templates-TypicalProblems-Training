#include <algorithm>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

const int maxn = 40005;
int f[maxn];
inline int find(int u) { return (f[u] == u) ? u : (f[u] = find(f[u])); }
inline void unit(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
        f[v] = f[u];
}

bool visit[maxn];
struct edge
{
    int to, next, dis;
} g[maxn * 2];
int head[maxn], tot;
void addEdge(int u, int v, int dis)
{
    g[tot].to = v;
    g[tot].dis = dis;
    g[tot].next = head[u];
    head[u] = tot++;
}

struct query
{
    int q, next;
    int id;
} q[maxn * 2];
int h[maxn], cnt;
void addQuery(int u, int v, int id)
{
    q[cnt].q = v;
    q[cnt].next = h[u];
    q[cnt].id = id;
    h[u] = cnt++;
}

int lca[maxn];
int dis[maxn];
int l[maxn], r[maxn];

void LCA(int u)
{
    visit[u] = true;
    for (int i = head[u]; i != -1; i = g[i].next)
    {
        int v = g[i].to;
        if (visit[v])
            continue;
        dis[v] = dis[u] + g[i].dis;
        LCA(v);
        unit(u, v);
    }

    for (int i = h[u]; i != -1; i = q[i].next)
    {
        int v = q[i].q;
        if (visit[v])
            lca[q[i].id] = find(v);
    }
}

int main(void)
{
    int T;
    cin >> T;
    while (T-- > 0)
    {

        int n, m;
        cin >> n >> m;

        for (int i = 0; i <= n; ++i)
            f[i] = i;
        tot = cnt = 0;
        memset(head, -1, sizeof(head));
        memset(h, -1, sizeof(head));
        memset(visit, false, sizeof(visit));

        int u, v, w;
        for (int i = 1; i < n; ++i)
        {
            cin >> u >> v >> w;
            addEdge(u, v, w);
            addEdge(v, u, w);
        }

        for (int i = 1; i <= m; ++i)
        {
            cin >> l[i] >> r[i];
            addQuery(l[i], r[i], i);
            addQuery(r[i], l[i], i);
        }
        dis[1] = 0;
        LCA(1);
        for (int i = 1; i <= m; ++i)
            cout << dis[l[i]] + dis[r[i]] - 2 * dis[lca[i]] << endl;
    }
}