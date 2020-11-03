#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 5;

int x[maxn], y[maxn];

int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				int dx1 = x[k] - x[j];
				int dx2 = x[i] - x[j];
				int dy1 = y[k] - y[j];
				int dy2 = y[i] - y[j];
				if (dx2 * dy1 - dx1 * dy2 == 0) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
