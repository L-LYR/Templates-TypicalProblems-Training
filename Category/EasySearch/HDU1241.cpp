#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 105;
const int maxs = maxn * maxn;

int m, n;
int f[maxs], r[maxs];
char grid[maxn][maxn];

int find(int u) { return (f[u] == u) ? u : (f[u] = find(f[u])); }
void merge(int u, int v) {
    int fu = find(u), fv = find(v);
    if (r[fu] < r[fv]) {
        f[fu] = fv;
    } else {
        f[fv] = fu;
        if (r[fu] == r[fv]) ++r[fu];
    }
}
bool isJoint(int u, int v) { return find(u) == find(v); }

int main(void) {
    while (true) {
        cin >> n >> m;
        if (n == 0) break;
        int tol = n * m;
        memset(r, 0, sizeof(r));
        for (int i = 0; i <= tol; ++i) f[i] = i;
        for (int i = 0; i < n; ++i) cin >> grid[i];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int c = i * m + j;
                if (grid[i][j] == '*') {
                    merge(tol, c);
                    continue;
                }
                // adjacent
                // eight directions
                // In loop, only take half of them into consideration.
                if (i > 0 && grid[i - 1][j] == '@') merge(c, c - m);
                if (j > 0 && grid[i][j - 1] == '@') merge(c, c - 1);
                if (i > 0 && j > 0 &&
                    grid[i - 1][j - 1] == '@') merge(c, c - 1 - m);
                if (i > 0 && j + 1 < m &&
                    grid[i - 1][j + 1] == '@') merge(c, c + 1 - m);
            }
        }
        int cnt = -1;
        for (int i = 0; i <= tol; ++i) {
            if (f[i] == i) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}