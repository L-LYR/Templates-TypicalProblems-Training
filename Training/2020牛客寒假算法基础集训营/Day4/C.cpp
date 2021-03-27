#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
using ll = long long;
const ll mod = 998244353;
const int maxn = 2e5 + 5;
ll a[maxn], segTree[maxn << 2];

inline int ls(int p) { return p << 1; }
inline int rs(int p) { return (p << 1) | 1; }
inline void pushUp(int p) { segTree[p] = (segTree[ls(p)] * segTree[rs(p)]) % mod; }
void build(int p, int l, int r)
{
    if (l == r)
    {
        segTree[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    pushUp(p);
}
ll query(int ql, int qr, int p, int l, int r)
{

    if (ql <= l && r <= qr)
        return segTree[p];

    int mid = (l + r) >> 1;

    ll res_l = 1, res_r = 1;
    if (ql <= mid)
        res_l *= query(ql, qr, ls(p), l, mid);
    if (qr > mid)
        res_r *= query(ql, qr, rs(p), mid + 1, r);
    return ((res_l % mod) * (res_r % mod)) % mod;
}

int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    build(1, 1, n);
    ll ans = 0;
    for (int i = 1; i <= n - k + 1; ++i)
        ans = max(ans, query(i, i + k - 1, 1, 1, n));

    printf("%lld\n", ans);
    return 0;
}