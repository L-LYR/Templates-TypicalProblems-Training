#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int maxn = 1505;
const int maxm = 5e5 + 5;

int grid[maxn][maxn];
int x[maxm], y[maxm];

int main(void) {
    int h, w, n, m;
    scanf("%d %d %d %d", &h, &w, &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x[i], &y[i]);
        grid[x[i]][y[i]] = 1;
    }
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        grid[a][b] = -1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = x[i] + 1; j <= h; ++j) {
            if (grid[j][y[i]] == -1) break;
            if (grid[j][y[i]] == 1) break;
            grid[j][y[i]] = 2;
        }
        for (int j = x[i] - 1; j > 0; --j) {
            if (grid[j][y[i]] == -1) break;
            if (grid[j][y[i]] == 1) break;
            grid[j][y[i]] = 2;
        }
        for (int j = y[i] - 1; j > 0; --j) {
            if (grid[x[i]][j] == -1) break;
            if (grid[x[i]][j] == 1) break;
            grid[x[i]][j] = 2;
        }
        for (int j = y[i] + 1; j <= w; ++j) {
            if (grid[x[i]][j] == -1) break;
            if (grid[x[i]][j] == 1) break;
            grid[x[i]][j] = 2;
        }
    }

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (grid[i][j] == 2) ans++;
        }
    }

    cout << ans + n << endl;
    return 0;
}