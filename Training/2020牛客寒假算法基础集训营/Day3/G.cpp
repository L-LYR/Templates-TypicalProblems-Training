#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

char str[maxn];

struct SegTree
{
    ll a[maxn << 2];
    ll t[maxn << 2];

    inline int ls(int p) { return p << 1; }
    inline int rs(int p) { return (p << 1) | 1; }
    inline int mid(int l, int r) { return (r + l) >> 1; }
    inline void pushUp(int p) { a[p] = a[ls(p)] + a[rs(p)]; }
    inline void modify(int p, int l, int r, ll d)
    {
        t[p] += d;
        a[p] += (r - l + 1) * d;
    }

    // void build(int p, int l, int r)
    // {
    //     if (l == r)
    //     {
    //         a[p] = 0;
    //         return;
    //     }
    //     int m = mid(l, r);
    //     build(ls(p), l, m);
    //     build(rs(p), m + 1, r);
    //     pushUp(p);
    // }
    void pushDown(int p, int l, int r)
    {
        int m = mid(l, r);
        modify(ls(p), l, m, t[p]);
        modify(rs(p), m + 1, r, t[p]);
        t[p] = 0;
    }
    // void change(int i, int p, int l, int r, ll d)
    // {
    //     if (l == r)
    //     {
    //         a[p] += d;
    //         return;
    //     }
    //     int m = mid(l, r);
    //     if (i <= m)
    //         change(i, ls(p), l, m, d);
    //     else
    //         change(i, rs(p), m + 1, r, d);
    //     pushUp(p);
    // }

    void update(int il, int ir, int p, int l, int r, ll d)
    {
        if (il <= l && r <= ir)
        {
            t[p] += d;
            a[p] += (r - l + 1) * d;
            return;
        }
        pushDown(p, l, r);
        int m = mid(l, r);
        if (il <= m)
            update(il, ir, ls(p), l, m, d);
        if (ir > m)
            update(il, ir, rs(p), m + 1, r, d);
        pushUp(p);
    }
    ll query(int ql, int qr, int p, int l, int r)
    {
        if (ql <= l && r <= qr)
            return a[p];
        int m = mid(l, r);
        ll res = 0;
        pushDown(p, l, r);
        if (ql <= m)
            res += query(ql, qr, ls(p), l, m);
        if (qr > m)
            res += query(ql, qr, rs(p), m + 1, r);
        return res;
    }
};
SegTree pre, suf;
int main(void)
{
    int n, m, q, pos;
    ll ans = 0;
    scanf("%d", &n);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; ++i)
    {
        if (str[i] == '1')
        {
            ans = (ans + pre.query(1, i, 1, 1, n)) % mod;
            if (i != n)
                pre.update(i + 1, n, 1, 1, n, 1);
            if (i != 1)
                suf.update(1, i - 1, 1, 1, n, 1);
        }
    }
    printf("%lld\n", ans);

    ll ps, ss; // prefix sum & suffix sum
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &q, &pos);
        ps = pre.query(1, pos, 1, 1, n);
        ss = suf.query(pos, n, 1, 1, n);
        if (q == 1)
        {
            ans = (ans + ps + ss) % mod;
            if (pos != n)
                pre.update(pos + 1, n, 1, 1, n, 1);
            if (pos != 1)
                suf.update(1, pos - 1, 1, 1, n, 1);
        }
        else
        {
            ans = ((ans - ps - ss) % mod + mod) % mod;
            if (pos != n)
                pre.update(pos + 1, n, 1, 1, n, -1);
            if (pos != 1)
                suf.update(1, pos - 1, 1, 1, n, -1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}