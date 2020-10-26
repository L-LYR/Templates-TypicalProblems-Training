#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main(void) {
    ull x, y, a, b;
    cin >> x >> y >> a >> b;

    // If choose a, we get x*a = x + x*(a-1)
    // If choose b, we get x+b
    // By comparing a-1 and b, we can make the choice.
    // It's obvious that when x is enough big, 
    // x*(a-1) must be bigger than b.
    // So we can only choose a at the very beginning.

    ull exp = 0;
    while (true) {
        if (x * (a - 1) < b) {
            x *= a;
            if (x >= y) break;
            exp++;
        } else {
            exp += (y - x - 1) / b;
            break;
        }
    }

    cout << exp << endl;

    return 0;
}