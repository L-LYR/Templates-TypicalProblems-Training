#include <iostream>
#include <cstring>
#include <string>
using namespace std;
using ll = long long;

const int maxn = 5e4 + 5;
ll t[maxn], s, n;
inline int lowbit(int x) { return x & -x; }
void add(int i, ll x) {
	while (i <= n) {
		t[i] += x;
		i += lowbit(i);
	}
}
ll query(int i) {
	ll res = 0;
	while (i > 0) {
		res += t[i];
		i -= lowbit(i);
	}
	return res;
}
ll query(int i, int j) {
	return query(j) - query(i - 1);
}

int main(void) {
	scanf("%lld", &s);
	for (int i = 1; i <= s; ++i) {
		memset(t, 0, sizeof(t));
		printf("Case %d:\n", i);
		scanf("%lld", &n);
		ll a, b;
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a);
			add(i, a);
		}

		char cmd[6];
		while (true) {
			scanf("%s", cmd);
			string tmp(cmd);
			if (tmp == "End") break;
			scanf("%lld %lld", &a, &b);
			if (tmp == "Add") add(a, b);
			else if (tmp == "Sub") add(a, -b);
			else if (tmp == "Query") printf("%lld\n", query(a, b));
		}
	}
	return 0;
}
