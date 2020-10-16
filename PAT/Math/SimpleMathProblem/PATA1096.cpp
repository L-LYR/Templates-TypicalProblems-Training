#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;

int main(void) {
    long long n;
    cin >> n;
    long long l, maxLen = 0;
    long long rootn = sqrt(n), i = 2;
    while (i <= rootn) {
        if (n % i != 0) {
            i++;
            continue;
        }
        int cnt = 0;
        long long temp = 1, j = i;
        for (;;) {
            temp *= j;
            if (n % temp != 0) break;
            cnt++;
            j++;
        }
        if (maxLen < cnt) {
            maxLen = cnt;
            l = i;
        }
        i++;
    }
    if (maxLen == 0) {
        cout << 1 << endl;
        cout << n << endl;
    } else {
        cout << maxLen << endl;
        for (long long i = 0; i < maxLen; ++i) {
            cout << l + i;
            if (i != maxLen - 1) cout << "*";
        }
        cout << endl;
    }
    return 0;
}