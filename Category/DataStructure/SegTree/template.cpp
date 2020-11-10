#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 2;
const int maxn = N * 4;

ll arr[N];
ll t[maxn];
ll tag[maxn];

inline int mid(int l, int r) { return (r - l) / 2 + l; }
inline int ls(int p) { return 2 * p; } 		// left son
inline int rs(int p) { return 2 * p + 1; } 	// right son
// push up for building and updating
inline void pushUp(int p) { t[p] = t[ls(p)] + t[rs(p)]; }

void build(int p, int l, int r) {
	if (l == r) {
		t[p] = arr[l];
		return;
	}
	int m = mid(l, r);
	build(ls(p), l, m);
	build(rs(p), m + 1, r);
	pushUp(p);
}

// func: add, multiply, min, max ......
void f(int p, int l, int r, ll d) {
	tag[p] = tag[p] + d;
	t[p] = t[p] + d * (r - l + 1);
}

void pushDown(int p, int l, int r) {
	int m = mid(l, r);
	f(ls(p), l, m, tag[p]);
	f(rs(p), m + 1, r, tag[p]);
	tag[p] = 0;
}

// interval modification
void update(int cl, int cr, int p, int l, int r, ll d) {
	if (cl <= l && r <= cr) {
		t[p] = t[p] + d * (r - l + 1);
		tag[p] = tag[p] + d;
		return;
	}
	// before updating, must push down the lazy tags.
	pushDown(p, l, r);
	int m = mid(l, r);
	if (cl <= m) update(cl, cr, ls(p), l, m, d);
	if (cr > m) update(cl, cr, rs(p), m + 1, r, d);
	// update from bottom to top;
	pushUp(p);
}

ll quary(int ql, int qr, int p, int l, int r) {
	ll res = 0;
	if (ql <= l && r <= qr) return t[p];
	int m = mid(l, r);
	pushDown(p, l, r);
	if (ql <= m) res = res + quary(ql, qr, ls(p), l, m);
	if (qr > m) res = res + quary(ql, qr, rs(p), m + 1, r);
	return res;
}


int main(void) {
	int n, m, c, a, b, d;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%lld", &arr[i]);
	build(1, 1, n);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &c);
		switch(c) {
			case 1:
				scanf("%d %d %d", &a, &b, &d);
				update(a, b, 1, 1, n, d);
				break;
			case 2:
				scanf("%d %d", &a, &b);
				printf("%lld\n", quary(a, b, 1, 1, n));
				break;
		}
	}
	return 0;
}
