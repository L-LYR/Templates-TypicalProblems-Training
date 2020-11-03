#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int maxn = 105;

struct DisjointSet {
	vector<int> f, r;
	
	DisjointSet(int n) {
		f.resize(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			f[i] = i;
		}
		r.resize(n + 1, 0);
	}

	int find(int v) { return (f[v] == v) ? v : (f[v] = find(f[v])); }
	
	void merge(int u, int v) {
		int fu = find(u), fv = find(v);
		if (r[fu] > r[fv]) {
			f[fv] = fu;
		} else {
			f[fu] = fv;
			if (r[fv] == r[fu]) r[fv]++;
		}
	}

	bool isJoint(int u, int v) { return find(u) == find(v); }
};


struct edge {
	int u, v, w;
	edge(int _u, int _v, int _w) 
		: u(_u), v(_v), w(_w) {}
};

bool operator<(const edge& l, const edge& r) {
	return l.w < r.w;
}

int w(int x1, int y1, int x2, int y2) {
	int dx = x1 - x2, dy = y1 - y2;
	int d = dx * dx + dy * dy;
	if (d < 100 || d > 1000000) {
		return -1;
	} else return d;
}

int x[maxn], y[maxn];

int main(void) {
	int t;
	scanf("%d", &t);
	while(t-- > 0) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d %d", &x[i], &y[i]);
		}
		vector<edge> es;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j) continue;
				int cw = w(x[i], y[i], x[j], y[j]);
				if (cw > 0) {
					es.push_back(edge(i, j, cw));
					es.push_back(edge(j, i, cw));
				}
			}
		}
		sort(es.begin(), es.end());
		double ans = 0;
		DisjointSet s(n);
		for (int i = 0; i < es.size(); ++i) {
			if (s.isJoint(es[i].u, es[i].v)) continue;
			s.merge(es[i].u, es[i].v);
			ans += sqrt(es[i].w) * 100;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (s.f[i] == i) cnt++;
		}

		if (cnt == 1) {
			printf("%0.1f\n", ans);
		} else {
			printf("oh!\n");
		}
	}
	return 0;
}
