#include <bits/stdc++.h>
using namespace std;
const auto N = 200005;
const auto maxn = N * 4;
#pragma GCC optimize("O2,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
inline auto closeSync() -> void {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
// This problem is explicitly about the segment tree.
// But I'm not familiar with it.

// auto arr = vector<long long>(N);
// auto rangesum = vector<long long>(maxn);
// auto tag = vector<long long>(maxn);
// auto rangemin = vector<long long>(maxn);
// auto rangemax = vector<long long>(maxn);

// Well, vector is slow
using ll = long long;
ll arr[N];
ll rangesum[maxn], tag[maxn];
ll rangemin[maxn], rangemax[maxn];

inline auto mid(int l, int r) -> int { return (r - l) / 2 + l; }
inline auto ls(int p) -> int { return 2 * p; }
inline auto rs(int p) -> int { return 2 * p + 1; }
inline auto pushUp(int p) -> void {
    rangemin[p] = min(rangemin[ls(p)], rangemin[rs(p)]);
    rangemax[p] = max(rangemax[ls(p)], rangemax[rs(p)]);
    rangesum[p] = rangesum[ls(p)] + rangesum[rs(p)];
}

auto build(int p, int l, int r) -> void {
    if (l == r) {
        rangemax[p] = rangemin[p] = rangesum[p] = arr[l];
        return;
    }
    build(ls(p), l, mid(l, r));
    build(rs(p), mid(l, r) + 1, r);
    pushUp(p);
}

// lazy update
inline auto f(int p, int l, int r, long long d) -> void {
    rangemax[p] = rangemin[p] = tag[p] = d;
    rangesum[p] = d * (r - l + 1);
}

inline auto pushDown(int p, int l, int r) -> void {
    if (tag[p] == 0) return;
    f(ls(p), l, mid(l, r), tag[p]);
    f(rs(p), mid(l, r) + 1, r, tag[p]);
    tag[p] = 0;
}

auto update(int cl, int cr, int p, int l, int r, long long d) -> void {
    if (cl <= l and r <= cr) {
        if (rangemin[p] >= d) return;
        if (rangemax[p] <= d) {
            f(p, l, r, d);
            return;
        }
    }
    pushDown(p, l, r);
    auto m = mid(l, r);
    if (cl <= m) update(cl, cr, ls(p), l, m, d);
    if (cr > m) update(cl, cr, rs(p), m + 1, r, d);
    pushUp(p);
}

// query for the sum of [ql, qr]
auto querySum(int ql, int qr, int p, int l, int r) -> long long {
    if (qr < ql) return 0ll;
    if (ql <= l and r <= qr) return rangesum[p];
    auto res = 0ll;
    auto m = mid(l, r);
    pushDown(p, l, r);
    if (ql <= m) res += querySum(ql, qr, ls(p), l, m);
    if (qr > m) res += querySum(ql, qr, rs(p), m + 1, r);
    return res;
}

// query for the first number that is less than v in [ql, qr]
auto queryMin(int ql, int qr, int p, int l, int r, long long v) -> int {
    if (rangemin[p] > v) return -1;
    if (l == r) return l;
    pushDown(p, l, r);
    auto m = mid(l, r);
    auto res = -1;
    if (ql <= m) res = queryMin(ql, qr, ls(p), l, m, v);
    if (res != -1) return res;
    if (qr > m) res = queryMin(ql, qr, rs(p), m + 1, r, v);
    return res;
}

// query for the right bound of the range sum [1, r] which is greater than v
auto queryBound(int p, int l, int r, long long v) -> int {
    if (l == r) {
        if (rangesum[p] <= v)
            return l;
        else
            return l - 1;
    }
    pushDown(p, l, r);
    if (rangesum[ls(p)] <= v)
        return queryBound(rs(p), mid(l, r) + 1, r, v - rangesum[ls(p)]);
    else
        return queryBound(ls(p), l, mid(l, r), v);
}

auto query(int x, long long y, int n) -> int {
    auto ans = 0;
    while (x <= n) {                     // search in [x, n]
        x = queryMin(x, n, 1, 1, n, y);  // find the left bound x
        if (x == -1) break;
        auto cursum = y + querySum(1, x - 1, 1, 1, n);
        auto nx = queryBound(1, 1, n, cursum);  // find the right bound nx
        ans += nx - x + 1;
        y -= querySum(x, nx, 1, 1, n);
        x = nx + 2;  // the nx+1-th one must be greater than the current y
        // this can be seen in the function queryBound
    }
    return ans;
}

auto main(void) -> int {
    closeSync();
    auto n = 0, q = 0, o = 0, x = 0, y = 0;
    cin >> n >> q;
    for (auto i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    while (q-- > 0) {
        cin >> o >> x >> y;
        switch (o) {
            case 1:
                update(1, x, 1, 1, n, y);
                break;
            case 2:
                cout << query(x, y, n) << endl;
                break;
        }
    }
    return 0;
}