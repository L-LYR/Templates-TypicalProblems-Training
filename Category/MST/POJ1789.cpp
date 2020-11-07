// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cstdio>
// #include <string>
// #include <cstring>
// using namespace std;

// const int maxn = 2005;
// const int inf = 0x3f3f3f3f;

// // struct DisjointSet {
// // 	vector<int> f, r;

// // 	DisjointSet() { set(0); }

// // 	void set(int n) {
// // 		f.resize(n + 1, 0);
// // 		for (int i = 1; i <= n; ++i) {
// // 			f[i] = i;
// // 		}
// // 		r.resize(n + 1, 0);
// // 	}

// // 	int find(int v) { return f[v] == v ? v : f[v] = find(f[v]); }

// // 	void merge(int u, int v) {
// // 		int fu = find(u), fv = find(v);
// // 		if (f[fu] > f[fv]) {
// // 			f[fv] = fu;
// // 		} else {
// // 			f[fu] = fv;
// // 			if (r[fv] == r[fu]) r[fv]++;
// // 		}
// // 	}

// // 	bool isJoint(int u, int v) { return find(u) == find(v); }
// // };

// // struct edge {
// // 	int u, v, w;
// // 	edge(int _u, int _v, int _w)
// // 		: u(_u), v(_v), w(_w) {}
// // };

// // bool operator<(const edge& l, const edge& r) {
// // 	return l.w < r.w;
// // }

// char t[maxn][8];
// int g[maxn][maxn];
// bool visited[maxn];
// int dis[maxn];
// // vector<edge> es;
// // DisjointSet s;

// int w(int i, int j) {
// 	int d = 0;
// 	for (int k = 0; k < 8; ++k) {
// 		if (t[i][k] != t[j][k]) d++;
// 	}
// 	return d;
// }

// int main(void) {
// 	int n;
// 	while (true) {
// 		cin >> n;
// 		if (n == 0) break;
// 		memset(g, 0, sizeof(g));
// 		for (int i = 1; i <= n; ++i) {
// 			scanf("%s", t[i]);
// 		}
// 		// es.clear();
// 		for (int i = 1; i <= n; ++i) {
// 			for (int j = 1; j <= n; ++j) {
// 				if (i == j) continue;
// 				int cw = w(i, j);
// 				g[i][j] = g[j][i] = cw;
// 		//		es.push_back(edge(i, j, cw));
// 		//		es.push_back(edge(j, i, cw));
// 			}
// 		}
// 		memset(visited, false, sizeof(visited));
// 		// s.set(n);
// 		// sort(es.begin(), es.end());
// 		// int ans = 0;
// 		// for (int i = 0; i < es.size(); ++i) {
// 		// 	if (s.isJoint(es[i].u, es[i].v)) continue;
// 		// 	s.merge(es[i].u, es[i].v);
// 		// 	ans += es[i].w;
// 		// }
// 		visited[1] = true;
// 		dis[1] = 0;
// 		for (int i = 2; i <= n; ++i) {
// 			dis[i] = g[1][i];
// 		}
// 		int ans = 0;
// 		for (int i = 1; i < n; ++i) {
// 			int min_v = -1;
// 			for (int j = 2; j <= n; ++j) {
// 				if (!visited[j] && (min_v == -1 || dis[j] < dis[min_v])) {
// 					min_v = j;
// 				}
// 			}
// 			visited[min_v] = true;
// 			ans += dis[min_v];
// 			for (int j = 2; j <= n; ++j) {
// 				if (!visited[j]) dis[j] = min(g[min_v][j], dis[j]);
// 			}
// 		}

// 		cout << "The highest possible quality is 1/" << ans << "." << endl;
// 	}

// 	return 0;
// }

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 2001;
struct edge {
    int u, v, w;
};
bool operator<(const edge& l, const edge& r) {
    return l.w < r.w;
}

char t[maxn][8];
int f[maxn];
edge es[maxn * maxn];
int n, tol, ans;

int find(int u) { return (f[u] == u) ? u : (f[u] = find(f[u])); }

int w(char* l, char* r) {
    int d = 0;
    for (int k = 0; k < 8; ++k)
        if (l[k] != r[k]) d++;
    return d;
}

int main(void) {
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; ++i) {
            scanf("%s", t[i]);
            f[i] = i;
        }
        tol = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                es[tol].u = i;
                es[tol].v = j;
                es[tol].w = w(t[i], t[j]);
                tol++;
            }
        }
        sort(es, es + tol);
        ans = 0;
        for (int i = 0; i < tol && n > 1; ++i) {
            if (find(es[i].u) == find(es[i].v)) continue;
            f[find(es[i].u)] = f[find(es[i].v)];
            ans += es[i].w;
            n--;
        }
        printf("The highest possible quality is 1/%d.\n", ans);
    }
    return 0;
}
