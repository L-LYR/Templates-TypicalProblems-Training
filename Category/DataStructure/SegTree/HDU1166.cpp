#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

const int N = 5e4+5;
const int maxn = N * 4;

ll a[N], t[maxn], tag[maxn];

inline int mid(int l, int r) { return (r - l) / 2 + l; }
inline int ls(int p) { return p * 2; }
inline int rs(int p) { return p * 2 + 1; }
inline void pushUp(int p) { t[p] = t[ls(p)] + t[rs(p)]; }

void build(int p, int l, int r) {
	if (l == r) {
		t[p] = a[l];
		return;
	}
	int m = mid(l, r);
	build(ls(p), l, m);
	build(rs(p), m + 1, r);
	pushUp(p);
}

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

void update(int ml, int mr, int p, int l, int r, ll d) {
	if (ml <= l && r <= mr) {
		f(p, l, r, d);
		return;
	}
	pushDown(p, l, r);
	int m = mid(l, r);
	if (ml <= m) update(ml, mr, ls(p), l, m, d);
	if (mr > m) update(ml, mr, rs(p), m + 1, r, d);
	pushUp(p);
}

ll query(int ql, int qr, int p, int l, int r) {
	ll res = 0;
	if (ql <= l && r <= qr) return t[p];
	int m = mid(l, r);
	if (ql <= m) res = res + query(ql, qr, ls(p), l, m);
	if (qr > m) res = res + query(ql, qr, rs(p), m + 1, r);
	return res;	
}

int main(void) {
	int s, n, b, d;
	char cmd[6];
	scanf("%d", &s);
	for (int i = 1; i <= s; ++i) {
		printf("Case %d:\n", i);
		scanf("%d", &n);
		for (int j = 1; j <= n; ++j) {
			scanf("%lld", &a[j]);
		}
		memset(t, 0, sizeof(t));
		memset(tag, 0, sizeof(tag));
		build(1, 1, n);
		while (true) {
			scanf("%s", cmd);
			string tmp(cmd);
			if (tmp == "End") break;
			scanf("%d %d", &b, &d);
			if (tmp == "Add") {
				update(b, b, 1, 1, n, d);
			} else if (tmp == "Sub") {
				update(b, b, 1, 1, n, -d);
			} else if (tmp == "Query") {
				printf("%lld\n", query(b, d, 1, 1, n));
			}
		}
	}
	
	return 0;
}
