#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 200;

inline int lowbit(int x) { return x & -x; }

#ifdef BASIC_VERSION
ll t[maxn];
// single point of modification
void add(int i, ll x) {
	while (i < maxn) {
		t[i] += x;
		i += lowbit(x);
	}
}
// single point of query
ll query(int i) {
	ll res = 0;
	while (i > 0) {
		res += t[i];
		i -= lowbit(x);
	}
	return res;
}
// interval sum
ll query(int i, int j) {
	return query(j) - query(i - 1);
}
#endif

#ifdef DIFFERENTIAL_VERSION
ll d[maxn]; // d[i] = a[i] - a[i - 1];

void add(int i, ll x) {
	while (i < maxn) {
		d[i] += x;
		i += lowbit(x);
	}
}

int add(int i, int j, int x) {
	add(i, x);
	add(j + 1, -x);
}

ll query(int i) {
	ll res = 0;
	while (i > 0) {
		res += d[i];
		i -= lowbit(x);
	}
	return res;
}
#endif

#ifdef FINAL_VERSION

#endif
