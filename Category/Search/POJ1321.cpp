#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 9;

int n, k, ans;
char b[maxn][maxn]; // board
bool c[maxn]; // col

void dfs(int cnt, int r) {
	if (cnt == k) {
		ans++;
		return;
	}

	if (r == n) return;
	// place in the current row
	for (int i = 0; i < n; ++i) {
		if (!c[i] && b[r][i] == '#') {
			c[i] = true;
			dfs(cnt + 1, r + 1);
			c[i] = false;
		}
	}
	// skip this row
	dfs(cnt, r + 1);
}

int main(void) {
	while (true) {
    	cin >> n >> k;
		if (n == -1) break;
		memset(b, 0, sizeof(b));
		memset(c, false, sizeof(c));
    	for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> b[i][j];
			}
		}
		ans = 0;
		dfs(0, 0);
		cout << ans << endl;
	}
    return 0;
}
