#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;
using ll = long long;

struct p
{
    ll z, w; // z = x + y, w = x - y;
};

const int maxn = 2e5 + 5;

p points[maxn];

int main(void)
{
    int n;
    cin >> n;
    ll x, y;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        points[i].z = x + y;
        points[i].w = x - y;
    }

    ll ans = 0;
    sort(points, points + n, [](const p &l, const p &r) -> bool {
        return l.z < r.z;
    });
    ans = points[n - 1].z - points[0].z;
    sort(points, points + n, [](const p &l, const p &r) -> bool {
        return l.w < r.w;
    });
    ans = max(ans, points[n - 1].w - points[0].w);
    cout << ans << endl;
    return 0;
}