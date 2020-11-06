#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = 305;

ll dp[maxn][maxn];
ll C[maxn][maxn];
ll path[maxn];

inline void add(ll &l, ll r) {
	l += r;
	if (l >= mod) l -= mod;
}

void calC(int n){
	C[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			add(C[i + 1][j], C[i][j]);
			add(C[i + 1][j + 1], C[i][j]);
		}
	}
}

// n-vertex graph
// no self-loop
// each vertex has only two degree
// number of path sequence
void calPath(int n) {
	path[1] = path[2] = 1ll;
	for (int i = 3; i <= n; ++i) path[i] = path[i - 1] * i % mod;
}

ll solve(int n, int m, int l) {
	memset(dp, 0, sizeof(dp));
 	dp[0][0] = 1ll;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (!dp[i][j]) continue;
        	// chain
			for (int k = 1; k <= l; ++k) {
				if (i + k > n) break;
				if (j + k - 1 > m) break;
				add(dp[i + k][j + k - 1], dp[i][j] * path[k] % mod * C[n - i - 1][k - 1] % mod);
			}
			// cycle
			for (int k = 2; k <= l; ++k) {
				if (i + k > n) break;
				if (j + k > m) break;
				add(dp[i + k][j + k], dp[i][j] * path[k - 1] % mod * C[n - i - 1][k - 1] % mod);
			}
		}
	}	
	
	return dp[n][m];
}


int main(void) {
    int n, m, l;
    cin >> n >> m >>l;

	calC(n);
	calPath(n);

	cout << (solve(n, m, l) - solve(n, m, l - 1) + mod) % mod << endl;

    return 0;
}
