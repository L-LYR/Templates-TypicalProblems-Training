#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
int main(void)
{
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    if (a + b <= c || a + c <= b || b + c <= a)
        printf("wtnl\n");
    else
    {
        double l = 0, r = a, m, d;
        while (l < r)
        {
            m = (r + l) / 2.0;
            d = a + c - 2 * m;
            if (d < b)
                r = m;
            else if (d > b)
                l = m;
            else
                break;
        }
        if (l >= r)
            printf("No\n");
        else
        {
            double ans[3] = {m, a - m, c - m};
            sort(ans, ans + 3);
            printf("Yes\n%0.2lf %0.2lf %0.2lf\n", ans[0], ans[1], ans[2]);
        }
    }

    return 0;
}