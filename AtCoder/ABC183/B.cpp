#include <bits/stdc++.h>
using namespace std;

int main(void) {
    long double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    printf("%.10Lf\n", (sy * gx + gy * sx) / (sy + gy));
    return 0;
}