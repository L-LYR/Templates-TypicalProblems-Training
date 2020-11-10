#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 2e5 + 5;
const int maxn = N * 4;

int arr[N];
int t[maxn];
int n, m, a, b;
char c[2];

inline int ls(int p) { return p * 2; }
inline int rs(int p) { return p * 2 + 1; }
inline int mid(int l, int r) { return (r - l) / 2 + l; }
inline void pushUp(int p) { t[p] = max(t[ls(p)], t[rs(p)]); }

void build(int p, int l, int r) {
    if (r == l) {
        t[p] = arr[l];
        return;
    }
    int m = mid(l, r);
    build(ls(p), l, m);
    build(rs(p), m + 1, r);
    pushUp(p);
}

void update(int i, int p, int l, int r, int x) {
    if (l == r) {
        t[p] = x;
        return;
    }
    int m = mid(l, r);
    if (i <= m)
        update(i, ls(p), l, m, x);
    else
        update(i, rs(p), m + 1, r, x);
    pushUp(p);
}

int query(int ql, int qr, int p, int l, int r) {
    int res = 0;
    if (ql <= l && r <= qr) return t[p];
    int m = mid(l, r);
    if (ql <= m)
        res = max(res,
                  query(ql, qr, ls(p), l, m));
    if (qr > m)
        res = max(res,
                  query(ql, qr, rs(p), m + 1, r));
    return res;
}

int main(void) {
    while (scanf("%d %d", &n, &m) == 2) {
        // fill(t, t + maxn, -inf);
        memset(t, 0, sizeof(t));
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        build(1, 1, n);
        for (int i = 1; i <= m; ++i) {
            scanf("%s %d %d", c, &a, &b);
            if (c[0] == 'U') {
                update(a, 1, 1, n, b);
            } else if (c[0] == 'Q') {
                printf("%d\n", query(a, b, 1, 1, n));
            }
        }
    }
    return 0;
}
