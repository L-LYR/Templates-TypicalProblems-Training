#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;

const int maxn = 10005, maxm = 200005;
int cnt = 1, h[maxn];
int nxt[maxm], to[maxm], cap[maxm];

inline void addedge(int u, int v, int w)
{
    to[++cnt] = v;
    cap[cnt] = w;
    nxt[cnt] = h[u];
    h[u] = cnt;
}

int dep[maxn], q[maxn], l, r;

bool bfs(int s, int t, int n)
{
    memset(dep, 0, (n + 1) * sizeof(dep[0]));
    l = r = 1;
    q[r] = s;
    dep[s] = 1;
    while (l <= r)
    {
        int u = q[l++];
        for (int p = h[u]; p != 0; p = nxt[p])
        {
            int v = to[p];
            if (cap[p] > 0 && dep[v] == 0)
            {
                dep[v] = dep[u] + 1;
                q[++r] = v;
            }
        }
    }
    return dep[t];
}

int dfs(int u, int t, int in)
{
    if (u == t)
        return in;
    int out = 0;
    for (int p = h[u]; p != 0 && in != 0; p = nxt[p])
    {
        int v = to[p];
        if (cap[p] > 0 && (dep[v] == dep[u] + 1))
        {
            int res = dfs(v, t, min(cap[p], in));
            cap[p] -= res;
            cap[p ^ 1] += res;
            in -= res;
            out += res;
        }
    }
    if (out == 0)
        dep[u] = 0;
    return out;
}
int dinic(int s, int t, int vn)
{
    int maxFlow = 0;
    while (bfs(s, t, vn))
        maxFlow += dfs(s, t, maxn);
    return maxFlow;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int vn, en, s, t;
    cin >> vn >> en >> s >> t;
    int bp, ep;
    int w;
    for (int i = 0; i < en; ++i)
    {
        cin >> bp >> ep >> w;
        addedge(bp, ep, w);
        addedge(ep, bp, 0);
    }
    clock_t start = clock();
    cout << "The maximum flow is ";
    cout << dinic(s, t, vn) << endl;
    clock_t end = clock();
    cout << "The time cost is " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}