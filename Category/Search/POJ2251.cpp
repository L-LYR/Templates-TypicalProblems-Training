#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 32;

struct location {
	int i, j, k, s;
	location(int _i = 0, int _j = 0, int _k = 0, int _s = 0) {
		i = _i;
		j = _j;
		k = _k;
		s = _s;
	}
};

inline bool operator==(const location& l, const location& r) {
	return l.i == r.i && l.j == r.j && l.k == r.k;
}

int l, r, c;
char m[maxn][maxn][maxn]; // maze
bool visited[maxn][maxn][maxn];
location s;

int d[8][3] = {
	{0, 0, 1},
	{0, 0, -1},
	{1, 0, 0},
	{0, 1, 0},
	{-1, 0, 0},
	{0, -1, 0},
};

int bfs() {
	queue<location> ql;
	ql.push(s);
	visited[s.i][s.j][s.k] = true;
	while (!ql.empty()) {
		location cur = ql.front();
		ql.pop();
		for (int t = 0; t < 6; ++t) {
			int x = cur.i + d[t][0];
			int y = cur.j + d[t][1];
			int z = cur.k + d[t][2];
			if (x < 0 || y < 0 || z < 0) continue;
			if (x >= l || y >= r || z >= c) continue;
			if (m[x][y][z] == '#' || visited[x][y][z]) continue;
			visited[x][y][z] = true;
			// if found, return immediately.
			// if not, it will cause TLE.(I don't know why.)
			if (m[x][y][z] == 'E') return cur.s + 1; 
			ql.push(location(x, y, z, cur.s + 1));
		}
	}
	return -1;
}

int main(void) {
	while (true) {
		cin >> l >> r >> c;
		if (l == 0) break;

		memset(m, 0, sizeof(m));
		memset(visited, false, sizeof(visited));
		char ch;
		for (int i = 0; i < l; ++i) 
			for (int j = 0; j < r; ++j)
				for (int k = 0; k < c; ++k) {
					cin >> ch;
					if (ch == 'S') {
						s = location(i, j, k, 0);
						m[i][j][k] = '.';
					} else {
						m[i][j][k] = ch;
					}
				}
		int ans = bfs();
		if (ans == -1) cout << "Trapped!" << endl;
		else cout << "Escaped in " << ans << " minute(s)." << endl;
	}
	return 0;
}
