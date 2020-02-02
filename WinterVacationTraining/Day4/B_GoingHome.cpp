// Reference: https://www.cnblogs.com/wenruo/p/5264235.html

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int maxn = 105;
const int inf = 0x3f3f3f3f;
int g[maxn][maxn]; // graph
struct node
{
    int x, y;
    node(int _x = 0, int _y = 0) : x(_x), y(_y){};
} m[maxn], h[maxn];                   // locations of men and house
int nm, nh;                           // number of men, number of houses
int linker[maxn], lm[maxn], lh[maxn]; // status of matching
int slack[maxn];                      // slack operations
bool vis_m[maxn], vis_h[maxn];        // memo

inline int cost(node u, node v) { return -1 * (abs(u.x - v.x) + abs(u.y - v.y)); }

bool dfs(int x)
{
    vis_m[x] = true;
    for (int y = 0; y < nh; ++y)
    {
        if (vis_h[y])
            continue;
        int temp = lm[x] + lh[y] - g[x][y];
        if (temp == 0)
        {
            vis_h[y] = true;
            if (linker[y] == -1 || dfs(linker[y]))
            {
                linker[y] = x;
                return true;
            }
        }
        else if (slack[y] > temp)
            slack[y] = temp;
    }
    return false;
}

int km()
{
    memset(linker, -1, sizeof(linker));
    memset(lh, 0, sizeof(lh));
    for (int i = 0; i < nm; ++i)
    {
        lm[i] = -inf;
        for (int j = 0; j < nh; ++j)
        {
            lm[i] = max(g[i][j], lm[i]);
        }
    }

    for (int x = 0; x < nm; ++x)
    {
        memset(slack, 0x3f, sizeof(slack));
        while (true)
        {
            memset(vis_h, false, sizeof(vis_h));
            memset(vis_m, false, sizeof(vis_m));

            if (dfs(x))
                break;

            int d = inf;
            for (int i = 0; i < nh; ++i)
                if (!vis_h[i] && d > slack[i])
                    d = slack[i];

            for (int i = 0; i < nm; ++i)
                if (vis_m[i])
                    lm[i] -= d;

            for (int i = 0; i < nh; ++i)
                if (vis_h[i])
                    lh[i] += d;
                else
                    slack[i] -= d;
        }
    }
    int ans = 0;
    for (int i = 0; i < nh; ++i)
        if (linker[i] != -1)
            ans += g[linker[i]][i];
    return ans;
}

int main(void)
{
    int N, M;
    while (scanf("%d %d", &N, &M) == 2 && N != 0)
    {
        nm = nh = 0;
        char buf[maxn];
        for (int r = 0; r < N; ++r)
        {
            scanf("%s", buf);
            for (int c = 0; c < M; ++c)
            {
                if (buf[c] == 'm')
                {
                    m[nm] = node(r, c);
                    ++nm;
                }
                else if (buf[c] == 'H')
                {
                    h[nh] = node(r, c);
                    ++nh;
                }
            }
        }

        for (int i = 0; i < nm; ++i)
        {
            for (int j = 0; j < nh; ++j)
            {
                g[i][j] = cost(m[i], h[j]);
            }
        }

        printf("%d\n", abs(km()));
    }
    return 0;
}