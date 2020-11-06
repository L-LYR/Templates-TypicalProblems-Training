#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;
const int maxn = 777; // casually chosen
int main(void) {
	int n, len, cnt;
	cin >> n;
	string s1, s2, target;
	for (int i = 1; i <= n; ++i) {
		cin >> len;
		cin >> s1 >> s2 >> target;
		cnt = 0;
		string tmp = "";
		while (cnt < maxn) {
			if (tmp == target) {
				cout << i << " " << cnt << endl;
				break;
			}
			tmp = "";
			for (int j = 0; j < len; ++j) tmp = tmp + s2[j] + s1[j];
			s1 = tmp.substr(0, len);
			s2 = tmp.substr(len);
			cnt++;
		}
		if (cnt == maxn) cout << i << " " << -1 << endl;
	}
	return 0;
}
