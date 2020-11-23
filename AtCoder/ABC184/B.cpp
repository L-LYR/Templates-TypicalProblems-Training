#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto n = 0, x = 0;
    auto s = string();
    cin >> n >> x >> s;
    for (auto c : s) {
        if (c == 'x' and x > 0) {
            x--;
        } else if (c == 'o') {
            x++;
        }
    }
    cout << x << endl;
    return 0;
}