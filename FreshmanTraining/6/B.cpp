#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 405;

int g[maxn][maxn];
int n, m;
int route[maxn][maxn];

int floyd(int choose)
{
    memset(route, 0x3f, sizeof(route));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (g[i][j] == choose)
                route[i][j] = 1;

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                route[i][j] = min(route[i][j], route[i][k] + route[k][j]);

    return route[1][n];
}

int main(void)
{
    int ep, bp;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> bp >> ep;
        g[bp][ep] = g[ep][bp] = 1;
    }

    //1 is the railway, 0 is the highway
    int route1 = floyd(1), route2 = floyd(0);
    if (route1 > 1e9 || route2 > 1e9)
        cout << "-1" << endl;
    else
        cout << max(route1, route2) << endl;
    return 0;
}