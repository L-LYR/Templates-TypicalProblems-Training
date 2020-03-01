#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int maxn = 5e5 + 5;
int col[maxn], l[maxn], r[maxn];
int cntR[maxn], cntL[maxn]; // recode the number of color_i on left or right
ll ta[maxn];                // tree array

inline int lowbit(int x) { return x & -x; }

inline void add(int p, int n, int d)
{
    while (p <= n)
    {
        ta[p] += d;
        p += lowbit(p);
    }
}

inline ll getSum(int p)
{
    ll res = 0;
    while (p > 0)
    {
        res += ta[p];
        p -= lowbit(p);
    }
    return res;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d", &col[i], &l[i], &r[i]);
        cntR[col[i]]++;
    }
    for (int i = 1; i <= n; ++i)
    {
        cntR[col[i]]--;                // current color seperated from the right set
        add(col[i], n, -cntL[col[i]]); // modify for current query
        printf("%lld ", getSum(r[i]) - getSum(l[i] - 1));
        add(col[i], n, cntR[col[i]]); // modify for next query
        cntL[col[i]]++;               // current color joined in the left set
    }
    printf("\n");

    return 0;
}