#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 2e5 + 5;

int arr[maxn], t[maxn];
int n, m, a, b;
char c[2];

inline int lowbit(int x) { return x & -x; }
void update(int i, int x) {
	arr[i] = x;
	while (i <= n) {
		t[i] = arr[i];
		for (int j = 1; j < lowbit(i); j <<= 1)
			t[i] = max(t[i], t[i - j]);
		i += lowbit(i);
	}
}
int query(int i, int j) {
	int ans = 0;
	while (j >= i) {
		ans = max(arr[j], ans);
		j--;
		while (j - lowbit(j) >= i) {
			ans = max(t[j], ans);
			j -= lowbit(j);
		}
	}
	return ans;
}

int main(void) {
	while (scanf("%d %d", &n, &m) == 2) {
		memset(t, 0, sizeof(t));
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a);
			update(i, a);
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%s %d %d", c, &a, &b);
			if (c[0] == 'Q') {
				printf("%d\n", query(a, b));
			} else if (c[0] == 'U') {
				update(a, b);
			}
		}
	}
	return 0;
}