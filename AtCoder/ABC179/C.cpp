#include <bits/stdc++.h>
using namespace std;
const long maxn = 1e6 + 5;
long n;
int main(void) {
    cin >> n;
    long ans = 0;
    // no need to check out all of the factors from 1 to N
    // a is fixed, b will be (n - c) / a
    // c > 0, b <= (n - 1) / a 
    // If we try to enumerate c from 1 to n - a, it's too slow.
    // And a majority of cases in the enumeration above are useless,
    // for n - c must be the multiple of a.
    // So we just count the cases that b is a positive integer.
    // b = 1, 2, 3, 4, ..., \lfloor (n - 1) / a \rfloor
    for (int a = 1; a < n; ++a) ans += (n - 1) / a;
    cout << ans << endl;
    return 0;
}