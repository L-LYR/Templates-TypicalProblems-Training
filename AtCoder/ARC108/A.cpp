#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto S = 0ull, P = 0ull;
    cin >> S >> P;
    auto l = S / 2, r = S;
    // This problem can be done by BF.
    // But I think bisection is more efficient.
    while (l < r) {
        auto m = (r - l) / 2 + l;
        auto c = P / m;
        // cout << c << " " << m << endl;
        if (c == S - m and P % m == 0) {
            cout << "Yes" << endl;
            return 0;
        } else if (c < S - m) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    cout << "No" << endl;
    return 0;
}