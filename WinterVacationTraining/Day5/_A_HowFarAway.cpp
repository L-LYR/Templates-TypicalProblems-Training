#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 4e4 + 5;
const int maxm = 205;
const int inf = 0x3f3f3f3f;

int f[maxn];
void init(int n)
{
    for (int i = 1; i <= n; ++i)
        f[i] = 1;
}
inline int find(int p) { return (f[p] == p) ? p : (f[p] = find(f[p])); }
inline void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
        f[y] = f[x];
}

struct edge
{
    int to, dis;
    edge(int t = 0, int d = 0) : to(t), dis(d) {}
};
vector<edge> g[maxn];

struct query
{
    int q, next;
    int id;
} q[maxn * 2];
int head[maxn], tot;
inline void addQuery(int u, int v, int id)
{
    q[tot].q = v;
    q[tot].next = head[u];
    q[tot].id = id;
    head[u] = tot++;
}

int lca[maxn], dis[maxn];
bool visit[maxn];
int l[maxm], r[maxm];
int n, m;

void LCA(int u)
{
    visit[u] = true;
    int len = g[u].size();
    for (int i = 0; i < len; ++i)
    {
        int v = g[u][i].to;
        if (visit[v])
            continue;
        dis[v] = dis[u] + g[u][i].dis;
        LCA(v);
        merge(u, v);
    }

    for (int i = head[u]; i != -1; i = q[i].next)
    {
        int v = q[i].q;
        if (visit[v])
            lca[q[i].id] = find(v);
    }
}

inline void init()
{
    for (int i = 0; i <= n; ++i)
        f[i] = i;
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(visit, false, sizeof(visit));
    for (int i = 0; i <= n; ++i)
        g[i].clear();
}

int main(void)
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        cin >> n >> m;
        init();
        for (int i = 1, u, v, d; i < n; ++i)
        {
            cin >> u >> v >> d;
            g[u].push_back(edge(v, d));
            g[v].push_back(edge(u, d));
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

    return 0;
}