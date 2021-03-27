#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
vector<double> vx, vy;

int main(void)
{
    double x_0, y_0;
    int n, k;
    cin >> x_0 >> y_0 >> n >> k;
    k = n - k;
    for (int i = 0; i < n; ++i)
    {
        double x, y;
        cin >> x >> y;
        if (x * x_0 < 0)
            vx.push_back(y_0 - x_0 * (y - y_0) / (x - x_0));
        if (y * y_0 < 0)
            vy.push_back(x_0 - y_0 * (x - x_0) / (y - y_0));
    }
    double minlen = 5e9;
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    if (vx.size() >= k)
    {
        for (int l = 0, r = k - 1, lim = vx.size(); r < lim; ++r, ++l)
            minlen = min(minlen, vx[r] - vx[l]);
    }
    if (vy.size() >= k)
    {
        for (int l = 0, r = k - 1, lim = vy.size(); r < lim; ++r, ++l)
            minlen = min(minlen, vy[r] - vy[l]);
    }
    if (minlen == 5e9)
        cout << -1 << endl;
    else
        cout << fixed << setprecision(8) << minlen << endl;
    return 0;
}