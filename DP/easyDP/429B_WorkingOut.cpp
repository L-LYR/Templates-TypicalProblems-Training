#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 1004
#define MAXM 1004

int a[MAXN][MAXM];
int dp1[MAXN][MAXM], dp2[MAXN][MAXM], dp3[MAXN][MAXM], dp4[MAXN][MAXM];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, i, j;
    cin >> n >> m;
    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            cin >> a[i][j];

    for (i = 1; i <= n; ++i)
        for (j = 1; j <= m; ++j)
            dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);

    for (i = 1; i <= n; ++i)
        for (j = m; j >= 1; --j)
            dp2[i][j] = a[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);

    for (i = n; i >= 1; --i)
        for (j = 1; j <= m; ++j)
            dp3[i][j] = a[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);

    for (i = n; i >= 1; --i)
        for (j = m; j >= 1; --j)
            dp4[i][j] = a[i][j] + max(dp4[i + 1][j], dp4[i][j + 1]);

    int ans = 0, cases[2];
    for (i = 2; i < n; ++i)
        for (j = 2; j < m; ++j)
        {
            ans = max(ans, dp3[i + 1][j] + dp2[i - 1][j] +
                               dp1[i][j - 1] + dp4[i][j + 1]);
            ans = max(ans, dp4[i + 1][j] + dp1[i - 1][j] +
                               dp3[i][j - 1] + dp2[i][j + 1]);
        }
    cout << ans << endl;
    return 0;
}
