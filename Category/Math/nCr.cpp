#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 305;
const int mod = 1e9 + 7;

ll C[maxn][maxn];

inline void add(ll &l, ll r) {
	l += r;
	if (l >= mod) l -= mod;
}

void cal(int n) {
	C[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			add(C[i + 1][j + 1], C[i][j]);
			add(C[i + 1][j], C[i][j]);
		}
	}	
}

int main(void) {
	int n = 300;
	cal(n);

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			printf("C(%d, %d) = %ld\n", j, i, C[i][j]);
		}
	}

	return 0;
}
