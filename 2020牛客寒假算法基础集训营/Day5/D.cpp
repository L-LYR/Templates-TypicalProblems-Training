#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double e = 1.0 / 3.0;

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T-- > 0)
    {
        double a, b;
        scanf("%lf%lf", &a, &b);
        double ans = 0;
        while (true)
        {
            double cur = cbrt(a);
            if (abs(b - cur) + 1.0 < abs(a - b))
            {
                a = cur;
                ans += 1.0;
            }
            else
            {
                ans += abs(b - a);
                break;
            }
        }
        printf("%0.9f\n", ans);
    }
    return 0;
}