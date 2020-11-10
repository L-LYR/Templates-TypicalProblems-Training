#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	while (n-- > 0) {
		int x;
		cin >> x;
		if (x == 1 || x == 2 || x == 4 || x == 5 || x == 8 || x == 11)
			cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
