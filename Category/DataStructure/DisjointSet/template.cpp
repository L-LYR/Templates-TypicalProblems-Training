#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;

#ifdef SIMPLE
int f[maxn];
void init(int n) {
	for (int i = 0; i <= n; ++i) f[i] = i;
}
int find(int u) { return (f[u] == u) ? u : find(f[u]); }
void merge(int u, int v) { f[find(u)] = f[find(v)]; }
#endif

#ifdef OPTIMIZED
int f[maxn], r[maxn];
int init(int n) {
	for (int i = 0; i <= n; ++i) f[i] = i;
	memset(r, 0, sizeof(r));
}
int find(int u) { return (f[u] == u) ? u : (f[u] = find(f[u])); }
void merge(int u, int v) {
	int fu = find(u), fv = find(v);
	if (fu == fv) return;
	if (r[fu] < r[fv]) {
		f[fu] = fv;
	} else {
		f[fv] = fu;
		if (r[fv] == r[fu]) ++r[fv];
	}
}
bool isJoint(int u, int v) { return find(u) == find(v); }
#endif
