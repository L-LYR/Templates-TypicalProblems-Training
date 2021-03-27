#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 1e5 + 5;
struct star
{
    int x, y, z;
} s[maxn];
bool operator<(const star &l, const star &r)
{
    if (l.x == r.x)
    {
        if (l.y == r.y)
            return l.z < r.z;
        else
            return l.y < r.y;
    }
    else
        return l.x < r.x;
}
int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 0, x, y, z; i < n; ++i)
    {
        scanf("%d%d%d", &x, &y, &z);
        s[i] = {x, y, z};
    }
    sort(s, s + n);
    int ans = 0;
    multiset<int> ms;
    for (int i = 0; i < n; ++i)
    {
        if (s[i].z == 0)
            ms.insert(s[i].y);
        else
        {
            auto k = ms.lower_bound(s[i].y);
            if (k != ms.begin())
            {
                --k;
                ms.erase(k);
                ans++;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}