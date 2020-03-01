#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
const int m = 1e9 + 7;
int k[maxn], b[maxn];
struct node
{
    ll k, b;
    node(ll k_ = 1, ll b_ = 0) : k(k_), b(b_) {}
} f[maxn << 2];
inline node operator+(const node &l, const node &r)
{
    return node(l.k * r.k % m, (l.b * r.k + r.b) % m);
}
inline int ls(int p) { return p << 1; }
inline int rs(int p) { return (p << 1) | 1; }
inline void pushUp(int p) { f[p] = f[ls(p)] + f[rs(p)]; }
void build(int p, int l, int r)
{
    if (l == r)
    {
        f[p] = node(k[l], b[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    pushUp(p);
}
inline void change(int i, int p, int l, int r, ll kk, ll bb)
{
    if (l == r)
    {
        f[p] = node(kk, bb);
        return;
    }
    int mid = (l + r) >> 1;
    if (i <= mid)
        change(i, ls(p), l, mid, kk, bb);
    else
        change(i, rs(p), mid + 1, r, kk, bb);
    pushUp(p);
}

node query(int ql, int qr, int p, int l, int r)
{
    if (ql <= l && r <= qr)
        return f[p];
    node res_l, res_r;
    int mid = (l + r) >> 1;
    if (ql <= mid)
        res_l = query(ql, qr, ls(p), l, mid);
    if (qr > mid)
        res_r = query(ql, qr, rs(p), mid + 1, r);
    return res_l + res_r;
}

int main(void)
{
    int ne, nq;
    scanf("%d%d", &ne, &nq);
    for (int i = 1; i <= ne; ++i)
        scanf("%d", &k[i]);
    for (int i = 1; i <= ne; ++i)
        scanf("%d", &b[i]);
    build(1, 1, ne);
    int id, l, r, i;
    for (int cnt = 0; cnt < nq; ++cnt)
    {
        scanf("%d", &id);
        switch (id)
        {
        case 1:
            scanf("%d%d%d", &i, &l, &r);
            change(i, 1, 1, ne, l, r);
            break;
        case 2:
            scanf("%d%d", &l, &r);
            node res = query(l, r, 1, 1, ne);
            printf("%lld\n", (res.k + res.b) % m);
            break;
        }
    }

    return 0;
}