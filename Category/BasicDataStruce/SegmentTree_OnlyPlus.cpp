//https://blog.csdn.net/zearot/article/details/52280189
//https://blog.csdn.net/zearot/article/details/48299459
//https://www.zhihu.com/search?type=content&q=zkw%E7%BA%BF%E6%AE%B5%E6%A0%91
#include <iostream>
#include <cstring>
using namespace std;
using ll = long long;
#define MAXN 100001

ll arr[MAXN], segTree[MAXN << 2], tag[MAXN << 2];

inline int ls(int p) { return p << 1; }
inline int rs(int p) { return (p << 1) | 1; }
inline void pushUp(int p) { segTree[p] = segTree[ls(p)] + segTree[rs(p)]; }

void build(int p, int l, int r)
{
    if (l == r)
    {
        segTree[p] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    pushUp(p);
}

inline void modify(int p, int l, int r, ll d)
{
    tag[p] += d;
    segTree[p] += (r - l + 1) * d;
}

inline void pushDown(int p, int l, int r)
{
    int mid = (l + r) >> 1;
    modify(ls(p), l, mid, tag[p]);
    modify(rs(p), mid + 1, r, tag[p]);
    tag[p] = 0;
}
// // update index i-th
// void add(int i, int p, int l, int r, int d)
// {
//     if (l == r)
//     {
//         segTree[p] += d;
//         return;
//     }
//     int mid = (l + r) >> 1;
//     // pushDown(p, mid - l + 1, r - mid); // both add and update needed
//     if (i <= mid)
//         add(i, ls(p), l, mid, d);
//     else
//         add(i, rs(p), mid + 1, r, d);
//     pushUp(p);
// }

// update interval [il, ir]
void update(int il, int ir, int p, int l, int r, ll d)
{
    if (il <= l && r <= ir)
    {
        tag[p] += d;
        segTree[p] += (r - l + 1) * d;
        return;
    }
    pushDown(p, l, r);
    int mid = (l + r) >> 1;
    if (il <= mid)
        update(il, ir, ls(p), l, mid, d);
    if (ir > mid)
        update(il, ir, rs(p), mid + 1, r, d);

    pushUp(p);
}

ll query(int ql, int qr, int p, int l, int r)
{
    ll res = 0;

    if (ql <= l && r <= qr)
        return segTree[p];

    int mid = (l + r) >> 1;
    pushDown(p, l, r);

    if (ql <= mid)
        res += query(ql, qr, ls(p), l, mid);
    if (qr > mid)
        res += query(ql, qr, rs(p), mid + 1, r);
    return res;
}

int main(void)
{
    int N, M, i;
    cin >> N >> M;
    for (i = 1; i <= N; ++i)
        cin >> arr[i];
    build(1, 1, N);
    int opt, x, y;
    ll k;
    for (i = 0; i < M; ++i)
    {
        cin >> opt;
        switch (opt)
        {
        case 1:
            cin >> x >> y >> k;
            update(x, y, 1, 1, N, k);
            break;
        case 2:
            cin >> x >> y;
            cout << query(x, y, 1, 1, N) << endl;
        }
    }
    return 0;
}