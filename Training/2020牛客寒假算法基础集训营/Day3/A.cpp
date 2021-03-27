#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxn = 55;
const ll mod = 1e9 + 7;
ll dp[maxn][maxn];
char maze[maxn][maxn];
int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", maze[i] + 1);
    dp[1][1] = 1;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (maze[i][j - 1] == 'R' || maze[i][j - 1] == 'B')
                dp[i][j] += dp[i][j - 1];
            if (maze[i - 1][j] == 'D' || maze[i - 1][j] == 'B')
                dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }
    printf("%lld\n", dp[n][m] % mod);
    return 0;
}