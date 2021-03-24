#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int maxn = 105;
int s[maxn];
int n;
int get_mod(int top) {
	int ans = 0;
	for (int i = 0; i <= top; i++) {
		ans = ((ans * 10) + s[i]) % n;
	}
	return ans;
}

int dfs(int i) {
	if (i == 100) return -1;
	int ret;
	s[i] = 0;
	if (get_mod(i) == 0) return i;
	s[i] = 1;
	if (get_mod(1) == 0) return i;
	if ((ret = dfs(i + 1)) != -1) return ret;
	s[i] = 0;
	if ((ret = dfs(i + 1)) != -1) return ret;

	return -1;
}

int main(void) {
	while(true) {
		cin >> n;
		if (n == 0) break;
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		memset(s, 0, sizeof(s));
		s[0] = 1;
		int ret = dfs(1);
		for (int i = 0; i <= ret; ++i) {
			cout << s[i];
		}
		cout << endl;
	}

	return 0;
}
