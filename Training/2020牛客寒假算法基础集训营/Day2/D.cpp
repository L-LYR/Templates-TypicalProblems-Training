#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxn = 505;
const double eps = 1e-10;
ll x[maxn], y[maxn];
inline ll distance(int i, int j)
{
    ll dx = x[i] - x[j], dy = y[i] - y[j];
    return dx * dx + dy * dy;
}
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> y[i];
    ll ans = 0;
    for (int a = 1; a <= n; ++a)
        for (int b = a + 1; b <= n; ++b)
            for (int c = b + 1; c <= n; ++c)
            {
                ll e[3];
                e[0] = distance(a, b);
                e[1] = distance(a, c);
                e[2] = distance(c, b);
                sort(e, e + 3);
                if ((sqrt(e[0]) + sqrt(e[1]) - sqrt(e[2])) <= eps)
                    continue;
                if (e[0] + e[1] - e[2] < 0)
                    ans++;
            }
    cout << ans << endl;
    return 0;
}