#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
const int maxn = 1005;
enum : int {
    N = 0,
    S,
    W,
    E,
    O,
};

struct step {
    int x, y, dep, ld;

    step(int x_ = 0, int y_ = 0, int dep_ = 0, int ld_ = -1)
            : x(x_), y(y_), dep(dep_), ld(ld_) {}
};

int res = 0;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool vis[2 * maxn][2 * maxn][5];
auto q = queue<step>();

void pushin(int nx, int ny, int d, int ld) {
    if (!vis[nx][ny][ld]) {
        vis[nx][ny][ld] = true;
        q.push(step(nx, ny, d + 1, ld));
    }
}

auto main() -> int {
    int n;
    cin >> n;
    memset(vis, false, sizeof(vis));
    for (int k = 0; k < 4; ++k) {
        auto cur = step(dx[k] + maxn, dy[k] + maxn, 1, k);
        vis[dx[k] + maxn][dy[k] + maxn][k] = true;
        q.push(cur);
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.dep == n) {
            if (!vis[cur.x][cur.y][O]) {
                vis[cur.x][cur.y][O] = true;
                res++;
            }
        } else {
            if (cur.ld == N || cur.ld == S) {
                pushin(cur.x + dx[W], cur.y + dy[W], cur.dep, W);
                pushin(cur.x + dx[E], cur.y + dy[E], cur.dep, E);
            } else {
                pushin(cur.x + dx[N], cur.y + dy[N], cur.dep, N);
                pushin(cur.x + dx[S], cur.y + dy[S], cur.dep, S);
            }
        }
    }
    cout << res << endl;
    return 0;
}