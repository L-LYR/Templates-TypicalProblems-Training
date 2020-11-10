#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;

const int maxn = 105;
const int maxm = 1e5 + 5;

int N, W;
ll w[maxn], v[maxn];
ll dp[maxm];

int main(void) {
	cin >> N >> W;
	for (int i = 0; i < N; ++i) {
		cin >> w[i] >> v[i];
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 1e5; j >= v[i]; --j) {
			dp[j] = min(dp[j - v[i]] + w[i], dp[j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < maxm; ++i) {
		if (dp[i] <= W) ans = max(i, ans);
	}
	cout << ans << endl;
	return 0;
}
