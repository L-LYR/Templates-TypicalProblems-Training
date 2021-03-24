#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

const int maxn = 1005;
const int inf = 0x3f3f3f3f;

struct step {
	int x, y, cnt;
	step(int _x = 0, int _y = 0, int _cnt = 0)
		: x(_x), y(_y), cnt(_cnt) {}
};

char maze[maxn][maxn];
int s[maxn][maxn];
bool visited[maxn][maxn];

step J;
queue<step> qs;

int t, n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


// First, do fire_dfs(）to get the quickest 
// possible time for each block when fire breaks 
// to each block. So Joe mustn't move to the block
// maze[i][k] after the timing s[i][j].
void fire_bfs() {
	while (!qs.empty()) {
		step cur = qs.front();
		qs.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (maze[nx][ny] == '#') continue;
			if (s[nx][ny] != inf) continue;
			qs.push(step(nx, ny, cur.cnt + 1));
			s[nx][ny] = cur.cnt + 1;
		}
	}
}

int joe_bfs() {
	while (!qs.empty()) qs.pop();
	memset(visited, 0, sizeof(visited));
	qs.push(J);
	visited[J.x][J.y] = true;
	while (!qs.empty()) {
		step cur = qs.front();
		qs.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
				return cur.cnt + 1;
			}
			if (maze[nx][ny] == '#') continue;
			if (cur.cnt + 1 >= s[nx][ny]) continue;
			if (visited[nx][ny]) continue;
			visited[nx][ny] = true;
			qs.push(step(nx, ny, cur.cnt + 1));
		}
	}
	return -1;
}

int main(void) {
	cin >> t;
	while (t-- > 0) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> maze[i];
		}

		// Do not forget !!!!!!
		while (!qs.empty()) qs.pop();
		memset(s, 0x3f, sizeof(s));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (maze[i][j] == 'J') {
					J = step(i, j, 0);
					maze[i][j] = '.';
				} else if (maze[i][j] == 'F') {
					qs.push(step(i, j, 0)); // there may be at least one
					s[i][j] = 0;
					maze[i][j] = '.';
				}
			}
		}
		fire_bfs();
		int ans = joe_bfs();
		if (ans == -1) cout << "IMPOSSIBLE" << endl;
		else cout << ans << endl;
	}
	return 0;
}
