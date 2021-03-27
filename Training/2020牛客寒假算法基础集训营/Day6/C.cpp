#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
struct node
{
    int x, y, idx;
    node(int x_ = 0, int y_ = 0, int i = 0)
        : x(x_), y(y_), idx(i) {}
} b[maxn];
int a[maxn], o[maxn];
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0, x, y; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        b[i] = {x, y, i};
    }
    sort(b, b + n, [](const node &l, const node &r) -> bool {
        return l.x < r.x;
    });
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int l = 0, r = ans;
        while (l <= r)
        {
            int m = (l + r) >> 1;
            if (a[m] < b[i].y)
                r = m - 1;
            else
                l = m + 1;
        }
        a[l] = b[i].y;
        if (l > ans)
            ans = l;
        o[b[i].idx] = l;
    }

    printf("%d\n", ans + 1);
    for (int i = 0; i < n; ++i)
        printf("%d ", o[i] + 1);
    printf("\n");

    return 0;
}