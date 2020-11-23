#include <bits/stdc++.h>
using namespace std;
using point = pair<int, int>;

const auto maxn = 2005;

auto h = 0, w = 0;

struct step {
    int x, y, c;
};

step s, g;
char maze[maxn][maxn];
bool visited[maxn][maxn];
vector<point> tp[26];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

auto main() -> int {
    cin >> h >> w;
    for (auto i = 0; i < h; ++i) cin >> maze[i];
    for (auto i = 0; i < h; ++i) {
        for (auto j = 0; j < w; ++j) {
            auto c = maze[i][j];
            if (islower(c)) {
                tp[c - 'a'].emplace_back(i, j);
            } else if (c == 'S') {
                s = {i, j, 0};
            } else if (c == 'G') {
                g = {i, j, 0};
            }
        }
    }

    auto q = queue<step>();
    q.push(s);
    visited[s.x][s.y] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.x == g.x and cur.y == g.y) {
            cout << cur.c << endl;
            return 0;
        }
        auto c = maze[cur.x][cur.y];
        if (islower(c)) {
            for (auto np : tp[c - 'a'])
                if (visited[np.first][np.second] == false) {
                    visited[np.first][np.second] = true;
                    q.push({np.first, np.second, cur.c + 1});
                }
        }
        for (auto k = 0; k < 4; ++k) {
            auto nx = cur.x + dx[k];
            auto ny = cur.y + dy[k];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (visited[nx][ny]) continue;
            if (maze[nx][ny] == '#') continue;
            visited[nx][ny] = true;
            q.push({nx, ny, cur.c + 1});
        }
    }
    cout << -1 << endl;
    return 0;
}