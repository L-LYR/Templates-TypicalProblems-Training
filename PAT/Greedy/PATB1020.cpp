#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

const int maxn = 1005;
// always choose the higher unit price
// remember to use double type
struct goods
{
    double s;
    double p;
    double pe;
};
goods cakes[maxn];
int main(void)
{
    int n;
    double need;
    cin >> n >> need;
    for (int i = 0; i < n; ++i)
        cin >> cakes[i].s;
    for (int i = 0; i < n; ++i)
    {
        cin >> cakes[i].p;
        cakes[i].pe = cakes[i].p / cakes[i].s;
    }
    sort(cakes, cakes + n, [](const goods &l, const goods &r) -> bool {
        return l.pe - r.pe > 0;
    });
    double ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (need >= cakes[i].s)
        {
            ans += cakes[i].p;
            need -= cakes[i].s;
        }
        else
        {
            ans += cakes[i].pe * need;
            break;
        }
    }

    printf("%.2f\n", ans);
    return 0;
}