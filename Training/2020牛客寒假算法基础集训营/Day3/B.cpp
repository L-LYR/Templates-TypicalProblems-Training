#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
const int maxn = 55;
const ll mod = 1e9 + 7;
char maze[maxn][maxn];
int main(void)
{
    ll k;
    scanf("%lld", &k);
    k %= mod;

    int n = 50; // fixed size
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                maze[i][j] = 'B';
            if (i == j + 1 || j > i + 1)
                maze[i][j] = 'R';
            if (i + 1 == j || i > j + 1)
                maze[i][j] = 'D';
        }
    }
    for (int i = 1; i <= n; ++i)
        maze[n][i] = 'R';
    maze[n - 1][n - 1] = maze[n - 1][n] = 'R';
    int i = 1;
    while (k > 0)
    {
        if (k & 1)
            maze[i + 1][i] = 'B';
        k >>= 1;
        i++;
    }

    printf("%d %d\n", n, n);
    for (int i = 1; i <= n; ++i)
        printf("%s\n", maze[i] + 1);

    return 0;
}