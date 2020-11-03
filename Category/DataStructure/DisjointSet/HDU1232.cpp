#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

struct DisjointSet {
	vector<int> f;
	vector<int> r;

	DisjointSet(int n) {
		f.resize(n + 1);
		for (int i = 0; i <= n; ++i) {
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
			if (r[fv] == r[fu])
				r[fv]++;
		}
	}

	bool isJoint(int u, int v) {
		return find(u) == find(v);
	}
};

int main(void) {
	int n, m;
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0) break;
		DisjointSet s(n);
		while (m-- > 0) {
			int u, v;
			scanf("%d %d", &u, &v);
			s.merge(u, v);
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (s.f[i] == i) ans++;
		}	
		cout << ans - 1 << endl;
	}	
	return 0;
}
