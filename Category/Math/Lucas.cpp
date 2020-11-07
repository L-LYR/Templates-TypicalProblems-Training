#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll mod = 1e9 + 7;

ll fp(ll x, ll e) {
	ll ans = 1;
	while (e > 0) {
		if (e & 1) 
			ans = ans * x % mod;
		e >>= 1;
		x = x * x % mod;
	}
	return ans;
}

ll inv(ll x) { return fp(x, mod - 2); }

ll C(ll n, ll m) {
	if (n < m) return 0;
	ll up = 1, down = 1;
	for (ll i = n - m + 1; i <= n; ++i)
		up = up * i % mod;
	for (ll i = 1; i <= m; ++i)
		down = down * i % mod;
	return up * inv(down) % mod;
}

ll Lucas(ll n, ll m) {
	if (m == 0) return 1;
	else return Lucas(n / mod, m / mod) * C(n % mod, m % mod) % mod;
}

