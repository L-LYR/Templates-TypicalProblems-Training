#include <bits/stdc++.h>

using namespace std;

int main(void) {
	string n;
	cin >> n;
	int len = n.length();

	if (len == 1) {
		if (n == "8") {
			cout << "Yes" << endl;
			return 0;
		} else {
			cout << "No" << endl;
			return 0;
		}
	}

	if (len == 2) {
		int k = stoi(n);
		swap(n[1], n[0]);
		int rk = stoi(n);
		if (k % 8 == 0 || rk % 8 == 0) {
			cout << "Yes" << endl;	
			return 0;
		} else {
			cout << "No" << endl;
			return 0;
		}
	}
	int cnt[10];
	memset(cnt, 0, sizeof(cnt));
	for (auto i: n) {
		cnt[i - '0']++;
	}
	int curCnt[10];
	for (int i = 104; i < 1000; i += 8) {
		memset(curCnt, 0, sizeof(curCnt));
		string cur = to_string(i);
		for (auto c: cur) {
			curCnt[c - '0']++;
		}
		if (curCnt[0] > 0) continue;
		bool flag = true;
		for (int j = 1; j <= 9; ++j) {
			if (curCnt[j] > cnt[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "Yes" << endl;
			return 0;
		}
	}

	cout << "No" << endl;
	return 0;
}
