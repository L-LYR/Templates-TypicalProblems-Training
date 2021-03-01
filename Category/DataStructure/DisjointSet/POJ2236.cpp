#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 1e3 + 5;

int f[maxn];
vector<int> g[maxn];
bool alive[maxn];
int x[maxn], y[maxn];
int n, d;

int find(int u) { return (f[u] == u) ? u : (f[u] = find(f[u])); }

void merge(int u, int v) {
	int fu = find(u), fv = find(v);
	if (fu != fv) f[fu] = f[fv];
}

inline int dis(int x1, int x2, int y1, int y2) {
	int dx = x1 - x2;
	int dy = y1 - y2;
	return dx * dx + dy * dy;
}

int main(void) {
	cin >> n >> d;
	d *= d;
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &x[i], &y[i]);
		f[i] = i;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (dis(x[i], x[j], y[i], y[j]) <= d) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
		}
	}
	char c;
	int p1, p2;
	while (scanf("%c ", &c) == 1) {
		if (c == 'O') {
			scanf("%d", &p1);
			alive[p1] = true;
			for (size_t i = 0; i < g[p1].size(); ++i)
				if (alive[g[p1][i]]) merge(p1, g[p1][i]);
		} else if (c == 'S'){
			scanf("%d %d", &p1, &p2);
			if (find(p1) == find(p2)) printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
    return 0;
}
