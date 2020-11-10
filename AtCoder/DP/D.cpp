#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;

const int maxn = 105;
const int maxm = 1e5 + 5;

int N, W;
int w[maxn], v[maxn];
ll dp[maxm];

int main(void) {
	cin >> N >> W;
	for (int i = 0; i < N; ++i) {
		cin >> w[i] >> v[i];
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; ++i) {
		for (int j = W; j >= w[i]; --j) {
			dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
		}
	}
	cout << dp[W] << endl;
	return 0;
}
