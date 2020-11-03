#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
#define PRIM
// #define KRUSKAL
#ifdef KRUSKAL
struct DisjointSet {
	vector<int> f, r;

	DisjointSet(int n) {
		f.resize(n + 1);
		for (int i = 1; i <= n; ++i) {
			f[i] = i;
		}
		r.resize(n + 1, 0);
	}

	int find(int v) { return f[v] == v ? v : (f[v] = find(f[v])); }

	void merge(int u, int v) {	
		int fu = find(u), fv = find(v);
		if (r[fu] > r[fv]) {
			f[fv] = fu;
		} else {
			f[fu] = fv;
			if (r[fu] == r[fv]) r[fv]++;
		}
	}
		
	bool isJoint(int u, int v) { return find(u) == find(v); }
};
#endif

struct edge {
	int u, v, w;
	edge(int _u, int _v, int _w)
		: u(_u), v(_v), w(_w) {}
};

bool operator<(const edge& l, const edge& r) {
	if (l.w != r.w) return l.w < r.w;
	else if (l.u != r.u) return l.u < r.u;
	else return l.v < r.v;
}

#ifdef PRIM

const int maxn = 105;
const int inf = 0x3f3f3f3f;

struct pqc {
	bool operator()(const edge& l, const edge& r) {
		return l.w > r.w;
	}
};

#endif

int main(void) {
	int n;
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;

		int m = n * (n - 1) / 2;

#ifdef KRUSKAL
		vector<edge> es;
		int u, v, w;
		while (m-- > 0) {
			scanf("%d %d %d", &u, &v, &w);
			es.push_back(edge(u, v, w));
			es.push_back(edge(v, u, w));
		}
		sort(es.begin(), es.end());
		int ans = 0;
		DisjointSet s(n);
		for (int i = 0; i < es.size(); ++i) {
			if (s.isJoint(es[i].u, es[i].v)) continue;
			s.merge(es[i].u, es[i].v);
			ans += es[i].w;
		}
		cout << ans << endl;
#endif

#ifdef PRIM
		int u, v, w;
		vector<vector<edge> > map(n + 1);
		vector<bool> visited(n + 1, false);
		while (m-- > 0) {
			scanf("%d %d %d", &u, &v, &w);
			map[u].push_back(edge(u, v, w));
			map[v].push_back(edge(v, u ,w));
		}
		int ans = 0;
		priority_queue<edge, vector<edge>, pqc> pqe;
		visited[1] = true;
		for (int i = 0; i < map[1].size(); ++i) {
			pqe.push(map[1][i]);
		}
		for (int i = 1; i < n; ++i) {
			edge min_e = pqe.top();
			while (visited[min_e.v] && !pqe.empty()) {
				min_e = pqe.top();
				pqe.pop();
			}
			ans += min_e.w;
			visited[min_e.v] = true;
			for (int j = 0; j < map[min_e.v].size(); ++j) {
				if (!visited[map[min_e.v][j].v]) {
					pqe.push(map[min_e.v][j]);
				}
			}
		}
		cout << ans << endl;
#endif
	}
	return 0;
}
