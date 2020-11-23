#include <bits/stdc++.h>
using namespace std;
auto canReach(long long x, long long y, long long a, long long b) -> bool {
    return x - y == a - b or
           x + y == a + b or
           (abs(x - a) + abs(y - b) <= 3);
}
auto main() -> int {
    auto x = 0ll, y = 0ll, a = 0ll, b = 0ll;
    cin >> x >> y >> a >> b;
    if (x == a and y == b) {
        cout << 0 << endl;
        return 0;
    } else if (canReach(x, y, a, b)) {
        cout << 1 << endl;
        return 0;
    } else {
        for (int k = 1; k <= 3; ++k) {
            if (canReach(x, y + k, a, b) || canReach(x, y - k, a, b)) {
                cout << 2 << endl;
                return 0;
            }
        }
        if ((a + b + x - y) % 2 == 0) {
            cout << 2 << endl;
            return 0;
        }
        cout << 3 << endl;
    }
    return 0;
}