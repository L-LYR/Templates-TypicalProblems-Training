#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll sum, a, b;
int main(void) {
	ll n;
	cin >> n;
	while (n-- > 0) {
		cin >> a >> b;
		sum += (a + b) * (b - a + 1) / 2;
	}
	cout << sum << endl;
	return 0;
}
