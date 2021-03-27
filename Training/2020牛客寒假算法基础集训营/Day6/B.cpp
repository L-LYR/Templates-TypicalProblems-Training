#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 1e6 + 5;
struct edge
{
    int to, next;
} e[maxn];
int to[maxn];
int head[maxn], low[maxn], dfn[maxn], stack[maxn], belong[maxn];
int idx, top, scc, tot, num[maxn];
bool inStack[maxn];
inline void addEdge(int u, int v)
{
    e[tot].to = v;
    e[tot].next = head[u];
    head[u] = tot++;
}
void tarjan(int u)
{
    int v;
    low[u] = dfn[u] = ++idx;
    stack[top++] = u;
    inStack[u] = true;
    for (int i = head[u]; i != -1; i = e[i].next)
    {
        v = e[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            if (low[u] > low[v])
                low[u] = low[v];
        }
        else if (inStack[v] && low[u] > dfn[v])
            low[u] = dfn[v];
    }
    if (low[u] == dfn[u])
    {
        ++scc;
        do
        {
            v = stack[--top];
            inStack[v] = false;
            belong[v] = scc;
            num[scc]++;
        } while (v != u);
    }
}
inline void solve(int n)
{
    memset(dfn, 0, sizeof(dfn));
    memset(inStack, false, sizeof(inStack));
    memset(num, 0, sizeof(num));
    idx = top = scc = 0;
    for (int i = 1; i <= n; ++i)
        if (!dfn[i])
            tarjan(i);
}
inline void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}
int ans;
// bool vis[maxn];
// int cnt[maxn];
// void dfs(int u)
// {
//     if (vis[u])
//         return;
//     vis[u] = true;
//     cnt[u] = num[u];
//     for (int i = head[u]; i != -1; i = e[i].next)
//     {
//         int v = e[i].to;
//         dfs(v);
//         ans = max(ans, cnt[u] + cnt[v]);
//         cnt[u] = max(cnt[u], num[u] + cnt[v]);
//     }
//     ans = max(cnt[u], ans);
// }
int deg[maxn], pre[maxn], f[maxn];
void topSort()
{
    queue<int> q;
    for (int i = 1; i <= scc; ++i)
        if (!deg[i])
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].next)
        {
            int v = e[i].to;
            pre[v] = max(pre[v], f[u]); // the max length before reaching v
            if (--deg[v] == 0)
            {
                q.push(v);
                f[v] = f[v] + pre[v]; // the max length of reaching v
            }
        }
    }
}

int main(void)
{
    init();

    int n;
    scanf("%d", &n);
    for (int i = 1, j; i <= n; ++i)
    {
        scanf("%d", &j);
        to[i] = j;
        addEdge(i, j);
    }

    solve(n);

    init();
    for (int i = 1; i <= n; ++i)
    {
        int u = belong[i], v = belong[to[i]];
        if (u != v)
        {
            addEdge(u, v);
            deg[v]++;
        }
    }
    // for (int i = 1; i <= scc; ++i)
    //     if (!vis[i])
    //         dfs(i);
    for (int i = 1; i <= scc; ++i)
        f[i] = num[i];
    topSort();
    for (int i = 1; i <= scc; ++i)
        ans = max(f[i], ans);
    printf("%d\n", ans);
    return 0;
}