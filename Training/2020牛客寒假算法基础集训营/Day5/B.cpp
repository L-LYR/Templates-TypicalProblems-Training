#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
const double eps = 1e-7;
int n;

struct node
{
    ll x, y;
} p[maxn];

double solve(double x)
{
    double minVal = 0, dis;
    for (int i = 0; i < n; ++i)
    {
        dis = p[i].x - x;
        dis = (dis * dis) + p[i].y;
        minVal = max(minVal, dis);
    }
    return minVal;
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 0, x, y; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        p[i] = {x, y};
        p[i].y *= y;
    }

    double m, mm, l = -1e4, r = 1e4;
    while (r - l > eps)
    {
        m = (l + r) / 2.0;
        mm = (m + r) / 2.0;
        if (solve(m) <= solve(mm))
            r = mm;
        else
            l = m;
    }
    printf("%lf\n", sqrt(solve(l)));
    return 0;
}