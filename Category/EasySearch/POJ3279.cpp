#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 20;
const int inf = 1 << 30;

int m, n;
int sq[maxn][maxn];
int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int newSq[maxn][maxn];
int curAns[maxn][maxn];
int sol[maxn][maxn];

void flip(int cx, int cy) {
	newSq[cx][cy] ^= 1;
	for (int i = 0; i < 4; ++i) {
		int x = cx + d[i][0];
		int y = cy + d[i][1];
		newSq[x][y] ^= 1;
	}
}

int solve(int cur) {
	memcpy(newSq, sq, sizeof(sq));
	memset(curAns, 0, sizeof(curAns));
	int cnt = 0;

	// first row
	for (int i = 0; i < n; ++i) {
		if (cur & (1 << i)) {
			flip(1, i + 1);
			curAns[1][i + 1] = 1;
			cnt++;
		}
	}

	// 2-nd - m-th rows
	for (int r = 1; r < m; ++r) {
		for (int l = 1; l <= n; ++l) {
			if (newSq[r][l] == 1) {
				flip(r + 1, l);
				curAns[r + 1][l] = 1;
				cnt++;
			}
		}
	}
	
	for (int i = 1; i <= n; ++i) {
		if (newSq[m][i] != 0) return inf;
	}
	return cnt;
}

int main(void) {
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> sq[i][j];
		}
	}
	
	// Binary Enumeration
	// only the first line
	int lim = 1 << n;
	int cnt = inf;
	for (int cur = 0; cur < lim; ++cur) { 
		int ret = solve(cur);
		if (ret < cnt) {
			cnt = ret;
			memcpy(sol, curAns, sizeof(curAns));
		}
	}

	if (cnt != inf) {
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				cout << sol[i][j] << " ";
			}
 			cout << endl;
		}
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
