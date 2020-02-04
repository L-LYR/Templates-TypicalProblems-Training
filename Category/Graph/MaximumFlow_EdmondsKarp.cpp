#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 10005; // max number of vertex
int vn, en;             // vertex number and edge number
int g[maxn][maxn];      // the adjacent matrix of graph
int pre[maxn];          // the previous node to the current node i
int f[maxn];            // the flow from starting node to the cur node

int bfs(int s, int t)
{
    queue<int> q;
    memset(pre, -1, sizeof(pre));

    q.push(s);
    pre[s] = 0;
    f[s] = inf;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == t)
            break;
        for (int i = 1; i <= vn; ++i)
        {
            if (i != cur && g[cur][i] > 0 && pre[i] == -1)
            {
                pre[i] = cur;
                f[i] = min(g[cur][i], f[cur]);
                q.push(i);
            }
        }
    }

    if (pre[t] != -1)
        return f[t];
    else
        return -1;
}

int EK(int s, int t)
{
    int maxFlow = 0, inc = 0;
    while ((inc = bfs(s, t)) != -1)
    {
        int k = t;
        while (k != s)
        {
            int last = pre[k];
            g[last][k] -= inc;
            g[k][last] += inc;
            k = last;
        }
        maxFlow += inc;
    }
    return maxFlow;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s, t;
    cin >> vn >> en >> s >> t;
    int bp, ep;
    int w;
    for (int i = 0; i < en; ++i)
    {
        cin >> bp >> ep >> w;
        g[bp][ep] += w;
    }
    clock_t start = clock();
    cout << "The maximum flow is ";
    cout << EK(s, t) << endl;
    clock_t end = clock();
    cout << "The time cost is " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}
