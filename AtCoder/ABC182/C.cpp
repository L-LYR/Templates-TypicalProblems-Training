#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long long n;
    cin >> n;
    char digits[19];
    sprintf(digits, "%lld", n);

    int len = strlen(digits);

    int lim = 1 << len;
    int ans = INT_MAX;
    for (int i = 1; i <= lim; ++i) {
        int cur = 0, cnt = len;
        for (int j = 0; j < len; ++j) {
            if ((i >> j) & 1) {
                cur += digits[j] - '0';
                cnt--;
            }
        }
        if (cur % 3 == 0) ans = min(ans, cnt);
    }
    if (ans == len)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}