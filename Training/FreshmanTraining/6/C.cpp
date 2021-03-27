#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const int maxn = 105;

int n, m;
// g is the weight of all edges
// path is the number of pathes between all pairs of vetex
// long long g[maxn][maxn], path[maxn][maxn];
double g[maxn][maxn], path[maxn][maxn];
const double inf = 1e9;
int main(void)
{
    cin >> n >> m;
    int u, v, w;

    //initialize double as infinit
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            g[i][j] = inf;
            path[i][j] = 0;
        }

    // memset(g, 0x3f, sizeof(g));

    //self-circle
    for (int i = 1; i <= n; ++i)
        g[i][i] = 0;

    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
        path[u][v] = path[v][u] = 1;
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // if (k == i || k == j || i == j)
                //     continue;
                if (g[i][k] + g[k][j] == g[i][j])
                    path[i][j] += path[i][k] * path[k][j];
                else if (g[i][k] + g[k][j] < g[i][j])
                {
                    g[i][j] = g[i][k] + g[k][j];
                    path[i][j] = path[i][k] * path[k][j];
                }
            }
        }
    }

    for (int k = 1; k <= n; ++k)
    {
        double I = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // if (k == i || k == j || i == j)
                //     continue;
                if (g[i][k] + g[k][j] == g[i][j] && path[i][j] > 0)
                    // I += ((double)path[i][k] * (double)path[k][j]) / (double)(path[i][j]);
                    I += (path[i][k] * path[k][j]) / (path[i][j]);
            }
        }
        cout << fixed << setprecision(3) << I << endl;
    }

    return 0;
}