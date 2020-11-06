#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 205;

struct step {
    int x, y, s;
    step(int _x, int _y, int _s)
        : x(_x), y(_y), s(_s) {}
};
char grid[maxn][maxn];
bool visited[maxn][maxn];
int cnt[maxn][maxn];
queue<step> qs;
int n, m;
int yx, yy, mx, my;
int x[maxn * maxn], y[maxn * maxn];  // KFC
int tol;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs(int i, int j) {
    memset(visited, false, sizeof(visited));
    qs.push(step(i, j, 0));
    visited[i][j] = true;

    while (!qs.empty()) {
        step cur = qs.front();
        qs.pop();

        for (int k = 0; k < 4; ++k) {
            int nx = cur.x + dx[k];
            int ny = cur.y + dy[k];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] == '#') continue;
            qs.push(step(nx, ny, cur.s + 1));
            visited[nx][ny] = true;
            cnt[nx][ny] += cur.s + 1;
        }
    }
}

int main(void) {
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i) cin >> grid[i];

        int tol = 0;
        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'Y') {
                    grid[i][j] = '.';
                    yx = i;
                    yy = j;
                }
                if (grid[i][j] == 'M') {
                    grid[i][j] = '.';
                    mx = i;
                    my = j;
                }
                if (grid[i][j] == '@') {
                    grid[i][j] = '.';
                    x[tol] = i;
                    y[tol] = j;
                    tol++;
                }
            }
        }

        bfs(yx, yy);
        bfs(mx, my);
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < tol; ++i) {
            if (cnt[x[i]][y[i]] == 0) continue;
            ans = min(ans, cnt[x[i]][y[i]]);
        }
        cout << ans * 11 << endl;
    }
    return 0;
}