#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 100005;
const int maxm = 200005;
// important!!!
// const int inf = 0x3f3f3f3f;
// respectively for long long
const long long inf = 0x3f3f3f3f3f3f3f3f;
int n, m;
struct edge
{
    int v, a, b;
    edge(int _v = 0, int _a = 0, int _b = 0)
        : v(_v), a(_a), b(_b) {}
};

struct qnode
{
    int v;
    long long l;
    qnode(int _v = 0, long long _l = 0) : v(_v), l(_l) {}
    bool operator<(const qnode &r) const
    {
        return l > r.l;
    }
};

vector<edge> g[maxn];
bool vis[maxn];
long long dist[maxn];

inline void addEdge(int u, int v, int a, int b)
{
    g[u].push_back(edge(v, a, b));
}

inline bool canMove(const edge &next, double curLevel)
{
    return (1ll << next.b) <= (next.a / curLevel + 1);
}

void dijkstra(int n, int s)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, false, sizeof(vis));

    priority_queue<qnode> q;
    dist[s] = 1;
    q.push(qnode(s, 1));
    qnode tmp;

    while (!q.empty())
    {
        tmp = q.top();
        q.pop();
        int u = tmp.v;
        long long ul = tmp.l;

        if (vis[u])
            continue;

        vis[u] = true;
        int len = g[u].size();
        for (int i = 0; i < len; ++i)
        {
            int v = g[u][i].v;
            int c = g[u][i].a;
            if (!vis[v] && dist[v] > ul + c && canMove(g[u][i], ul))
            {
                dist[v] = ul + c;
                q.push(qnode(v, dist[v]));
            }
        }
    }
}

int main(void)
{
    int t, u, v, a, b;
    scanf("%d", &t);
    while (t-- > 0)
    {
        for (int i = 1; i <= n; ++i)
            g[i].clear();
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d %d %d", &u, &v, &a, &b);
            addEdge(u, v, a, b);
        }

        dijkstra(n, 1);

        if (dist[n] != inf)
            cout << floor(log2(dist[n])) << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}