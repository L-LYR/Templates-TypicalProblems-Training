#include <bits/stdc++.h>

using namespace std;

auto main(void) -> int {
    auto t = 0;
    cin >> t;
    while (t-- > 0) {
        auto x = 0, y = 0;
        cin >> x >> y;
        if (x == y)
            cout << x + y << endl;
        else
            cout << max(x, y) * 2 - 1 << endl;
    }
    return 0;
}