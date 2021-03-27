// Reference: https://www.luogu.com.cn/blog/styx-ferryman/chu-tan-tarjan-suan-fa-qiu-qiang-lian-tong-fen-liang-post
//            https://blog.csdn.net/u013480600/article/details/32162977

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

int n, m;
const int maxn = 20010;
vector<int> g[maxn];     // adjacent list
int dfs_n[maxn];         // dfs number
int low[maxn];           // lowest No.
stack<int> s;            // stack
int color[maxn];         // the block color
bool inStack[maxn];      // whether the vertex is in stack
int depth, sum;          // depth and color sum
int in[maxn], out[maxn]; // each block's in-degree and out-degree

void tarjan(int u)
{
    int v;
    low[u] = dfs_n[u] = ++depth;
    s.push(u);
    inStack[u] = true;
    int len = g[u].size();
    for (int i = 0; i < len; ++i)
    {
        v = g[u][i];
        if (!dfs_n[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v] && (low[u] > dfs_n[v]))
            low[u] = dfs_n[v];
    }

    if (dfs_n[u] == low[u])
    {
        ++sum;
        do
        {
            v = s.top();
            s.pop();
            inStack[v] = false;
            color[v] = sum;
        } while (v != u);
    }
}

int main(void)
{
    while (scanf("%d %d", &n, &m) == 2)
    {
        for (int i = 1; i <= n; ++i)
            g[i].clear();
        depth = sum = 0;
        int r, c;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d", &r, &c);
            g[r].push_back(c);
        }

        memset(low, 0, sizeof(low));
        memset(dfs_n, 0, sizeof(dfs_n));
        memset(inStack, false, sizeof(inStack));
        for (int i = 1; i <= n; ++i)
            if (!dfs_n[i])
                tarjan(i);

        // cout << sum << endl;

        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        for (int u = 1; u <= n; ++u)
        {
            int len = g[u].size();
            for (int i = 0; i < len; ++i)
            {
                int v = g[u][i];
                int x = color[u], y = color[v];
                if (x != y)
                {
                    out[x]++;
                    in[y]++;
                }
            }
        }

        int in_sum = 0, out_sum = 0;
        for (int i = 1; i <= sum; ++i)
        {
            if (!in[i])
                in_sum++;
            if (!out[i])
                out_sum++;
        }
        // When sum = 1, there is only one block.
        // in_sum = out_sum = 1, but we don't need to add any edge.
        if (sum == 1)
            cout << 0 << endl;
        else
            cout << max(in_sum, out_sum) << endl;
    }

    return 0;
}