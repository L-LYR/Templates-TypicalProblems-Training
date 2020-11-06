#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 15;

struct step {
    int x, y, s;
    step(int _x = 0, int _y = 0, int _s = 0)
        : x(_x), y(_y), s(_s) {}
};
int f[maxn * maxn];
char grid[maxn][maxn];
bool visited[maxn][maxn];
int gx[maxn * maxn];
int gy[maxn * maxn];
int T, n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
queue<step> qp;

int find(int u) { return (f[u] == u) ? u : (f[u] = find(f[u])); }
void merge(int u, int v) { f[find(u)] = find(v); }
bool isJoint(int u, int v) { return find(u) == find(v); }

int bfs(step i, step j) {
    memset(visited, 0, sizeof(visited));
    qp.push(i);
    visited[i.x][i.y] = true;
    if (j.x != i.x || j.y != i.y) {
        qp.push(j);
        visited[j.x][j.y] = true;
    }

    int ret = 0;
    while (!qp.empty()) {
        step cur = qp.front();
        qp.pop();
        ret = max(ret, cur.s);

        for (int k = 0; k < 4; ++k) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (grid[nx][ny] == '.') continue;
            if (visited[nx][ny]) continue;
            qp.push(step(nx, ny, cur.s + 1));
            visited[nx][ny] = true;
        }
    }
    return ret;
}

int main(void) {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) cin >> grid[i];

        int tol = 0;
        for (int i = 0; i <= m * n; ++i) f[i] = i;
        // First, use disjoint set to find the number of blocks.
        // There must be one or two blocks.
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int cur = i * m + j;
                if (grid[i][j] == '.') {
                    merge(m * n, cur);
                    continue;
                }
                gx[tol] = i;
                gy[tol++] = j;
                if (i > 0 && grid[i - 1][j] == '#') merge(cur, cur - m);
                if (j > 0 && grid[i][j - 1] == '#') merge(cur, cur - 1);
            }
        }

        int cnt = -1;
        for (int i = 0; i <= m * n; ++i)
            if (f[i] == i) cnt++;
        if (cnt > 2) {
            cout << "Case " << t << ": " << -1 << endl;
            continue;
        }
        // Two starting points
        // BFS
        int ans = inf;
        for (int i = 0; i < tol; ++i) {
            for (int j = 0; j < tol; ++j) {
                int ci = gx[i] * m + gy[i];
                int cj = gx[j] * m + gy[j];
                if (cnt == 2 && isJoint(ci, cj)) continue;
                ans = min(ans, bfs(step(gx[i], gy[i], 0), step(gx[j], gy[j], 0)));
            }
        }
        if (ans == inf) ans = 0;
        cout << "Case " << t << ": " << ans << endl;
    }
    return 0;
}