// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <string>
// #include <vector>
// #include <cstdio>
// #include <queue>
// using namespace std;

// #define PRIM
// // #define KRUSKAL
// #ifdef KRUSKAL
// struct DisjointSet {
// 	vector<int> f, r;

// 	DisjointSet(int n) {
// 		f.resize(n + 1);
// 		for (int i = 1; i <= n; ++i) {
// 			f[i] = i;
// 		}
// 		r.resize(n + 1, 0);
// 	}

// 	int find(int v) { return f[v] == v ? v : (f[v] = find(f[v])); }

// 	void merge(int u, int v) {
// 		int fu = find(u), fv = find(v);
// 		if (r[fu] > r[fv]) {
// 			f[fv] = fu;
// 		} else {
// 			f[fu] = fv;
// 			if (r[fu] == r[fv]) r[fv]++;
// 		}
// 	}

// 	bool isJoint(int u, int v) { return find(u) == find(v); }
// };
// #endif

// struct edge {
// 	int u, v, w;
// 	edge(int _u, int _v, int _w)
// 		: u(_u), v(_v), w(_w) {}
// };

// bool operator<(const edge& l, const edge& r) {
// 	if (l.w != r.w) return l.w < r.w;
// 	else if (l.u != r.u) return l.u < r.u;
// 	else return l.v < r.v;
// }

// #ifdef PRIM

// const int maxn = 105;
// const int inf = 0x3f3f3f3f;

// struct pqc {
// 	bool operator()(const edge& l, const edge& r) {
// 		return l.w > r.w;
// 	}
// };

// #endif

// int main(void) {
// 	int n;
// 	while (true) {
// 		scanf("%d", &n);
// 		if (n == 0) break;

// 		int m = n * (n - 1) / 2;

// #ifdef KRUSKAL
// 		vector<edge> es;
// 		int u, v, w;
// 		while (m-- > 0) {
// 			scanf("%d %d %d", &u, &v, &w);
// 			es.push_back(edge(u, v, w));
// 			es.push_back(edge(v, u, w));
// 		}
// 		sort(es.begin(), es.end());
// 		int ans = 0;
// 		DisjointSet s(n);
// 		for (int i = 0; i < es.size(); ++i) {
// 			if (s.isJoint(es[i].u, es[i].v)) continue;
// 			s.merge(es[i].u, es[i].v);
// 			ans += es[i].w;
// 		}
// 		cout << ans << endl;
// #endif

// #ifdef PRIM
// 		int u, v, w;
// 		vector<vector<edge> > map(n + 1);
// 		vector<bool> visited(n + 1, false);
// 		while (m-- > 0) {
// 			scanf("%d %d %d", &u, &v, &w);
// 			map[u].push_back(edge(u, v, w));
// 			map[v].push_back(edge(v, u ,w));
// 		}
// 		int ans = 0;
// 		priority_queue<edge, vector<edge>, pqc> pqe;
// 		visited[1] = true;
// 		for (int i = 0; i < map[1].size(); ++i) {
// 			pqe.push(map[1][i]);
// 		}
// 		for (int i = 1; i < n; ++i) {
// 			edge min_e = pqe.top();
// 			while (visited[min_e.v] && !pqe.empty()) {
// 				min_e = pqe.top();
// 				pqe.pop();
// 			}
// 			ans += min_e.w;
// 			visited[min_e.v] = true;
// 			for (int j = 0; j < map[min_e.v].size(); ++j) {
// 				if (!visited[map[min_e.v][j].v]) {
// 					pqe.push(map[min_e.v][j]);
// 				}
// 			}
// 		}
// 		cout << ans << endl;
// #endif
// 	}
// 	return 0;
// }

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int maxn = 101;
const int maxm = maxn * maxn;

struct edge {
    int to, w, next;
};
edge edges[maxm];
int head[maxn], d[maxn];
int tol, n;
bool vis[maxn];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > q;

inline int dis(char *s, char *t) {
    int ans = 0;
    for (int k = 0; k < 7; k++)
        if (s[k] != t[k]) ans++;
    return ans;
}

inline void init() {
    memset(edges, 0, sizeof(edges));
    memset(head, 0, sizeof(head));
    tol = 0;
}

inline void add(int from, int to, int w) {
    ++tol;
    edges[tol].w = w;
    edges[tol].to = to;
    edges[tol].next = head[from];
    head[from] = tol;
}

int prim() {
    while (!q.empty()) q.pop();
    q.push(make_pair(0, 1));
    memset(d, 0x3f, sizeof(d));
    memset(vis, false, sizeof(vis));

    int ans = 0, cnt = 0;
    while (!q.empty() && cnt < n) {
        int cd = q.top().first;
        int u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        ans += cd;
        cnt++;
        vis[u] = true;
        for (int i = head[u]; i != 0; i = edges[i].next) {
            if (edges[i].w < d[edges[i].to]) {
                d[edges[i].to] = edges[i].w;
                q.push(make_pair(edges[i].w, edges[i].to));
            }
        }
    }
    return ans;
}

int main() {
    int m, a, b, c;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        init();
        m = n * (n - 1) / 2;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
            add(b, a, c);
        }
        printf("%d\n", prim());
    }
    return 0;
}