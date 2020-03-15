#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <ctime>
using namespace std;
#define inf 1000000010
int n, m, s, t;
struct Edge
{
    int v, w, next;
} e[300005];
int head[300005], tot = 1;
void add(int u, int v, int w)
{
    tot++;
    e[tot].v = v;
    e[tot].w = w;
    e[tot].next = head[u];
    head[u] = tot;

    tot++;
    e[tot].v = u;
    e[tot].w = 0;
    e[tot].next = head[v];
    head[v] = tot;
}
int gap[300005], d[300005], cur[300005];
queue<int> que;
void init(int s, int t)
{
    d[t] = 1, gap[1]++;
    for (int i = 1; i <= n; i++)
        cur[i] = head[i];
    que.push(t);
    while (!que.empty())
    {
        int x = que.front();
        que.pop();
        for (int i = head[x]; i; i = e[i].next)
        {
            if (!d[e[i].v])
            {
                d[e[i].v] = d[x] + 1;
                gap[d[x] + 1]++;
                que.push(e[i].v);
            }
        }
    }
}
int dfs(int x, int s, int t, int flow)
{
    if (x == t)
        return flow;
    int flowed = 0;
    for (int &i = cur[x]; i; i = e[i].next)
    {
        if (d[x] == d[e[i].v] + 1)
        {
            int tmp = dfs(e[i].v, s, t, min(flow, e[i].w));
            flowed += tmp, flow -= tmp, e[i].w -= tmp, e[i ^ 1].w += tmp;
            if (!flow)
                return flowed;
        }
    }
    gap[d[x]]--;
    if (!gap[d[x]])
        d[s] = n + 1;
    d[x]++;
    gap[d[x]]++;
    cur[x] = head[x];
    return flowed;
}
int ISAP(int s, int t)
{
    init(s, t);
    int ret = dfs(s, s, t, inf);
    while (d[s] <= n)
        ret += dfs(s, s, t, inf);
    return ret;
}
int main(void)
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    clock_t start = clock();
    cout << "The maximum flow is ";
    cout << ISAP(s, t) << endl;
    clock_t end = clock();
    cout << "The time cost is " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}