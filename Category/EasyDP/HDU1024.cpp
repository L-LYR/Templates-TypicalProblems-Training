#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxn = 1e6 + 5;

int arr[maxn];
ll pre[maxn];
ll dp[maxn][maxn];
int m, n;

int main(void) {
	while (scanf("%d %d", &m, &n) == 2) {
		pre[0] = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			pre[i + 1] = pre[i] + arr[i];
		}
		
	}
	return 0;
}
