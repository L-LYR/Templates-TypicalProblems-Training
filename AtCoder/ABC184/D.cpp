#include <bits/stdc++.h>
using namespace std;

int a, b, c;
long double dp[101][101][101];
auto solve(int x, int y, int z) -> long double {
    if (x == 100 || y == 100 || z == 100)
        return (x - a) + (y - b) + (z - c);
    if (dp[x][y][z] != -1.0) return dp[x][y][z];
    auto res = ((long double)x / (long double)(x + y + z)) * solve(x + 1, y, z);
    res += ((long double)y / (long double)(x + y + z)) * solve(x, y + 1, z);
    res += ((long double)z / (long double)(x + y + z)) * solve(x, y, z + 1);
    dp[x][y][z] = res;
    return res;
};
auto main() -> int {
    cin >> a >> b >> c;
    fill_n((long double*)dp, 101 * 101 * 101, -1.0);
    cout << fixed << setprecision(12) << solve(a, b, c) << endl;
    return 0;
}