#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2001;
struct edge {
    int u, v, w;
};
bool operator<(const edge& l, const edge& r) {
    return l.w < r.w;
}
edge es[maxn * maxn];

char truck[maxn][8];
int f[maxn];
int r[maxn];
int n, tol, ans;

void init(int n) {
    for (int i = 0; i <= n; ++i) f[i] = i;
    memset(r, 0, sizeof(r));
}
int find(int u) { return (f[u] == u) ? u : (f[u] = find(f[u])); }
inline void merge(int u, int v) {
    int fu = find(u), fv = find(v);
    if (r[fu] <= r[fv])
        f[fu] = fv;
    else
        f[fv] = fu;
    if (r[fu] == r[fv] && fu != fv)
        r[fv]++;
}
bool isJoint(int u, int v) { return find(u) == find(v); }

int w(char* l, char* r) {
    int d = 0;
    for (int k = 0; k < 8; ++k)
        if (l[k] != r[k]) d++;
    return d;
}

int main(void) {
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; ++i)
            scanf("%s", truck[i]);
        tol = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                es[tol].u = i;
                es[tol].v = j;
                es[tol].w = w(truck[i], truck[j]);
                tol++;
            }
        }
        sort(es, es + tol);
        ans = 0;
        init(n);
        for (int i = 0; i < tol; ++i) {
            if (isJoint(es[i].u, es[i].v)) continue;
            merge(es[i].u, es[i].v);
            ans += es[i].w;
        }
        printf("The highest possible quality is 1/%d.\n", ans);
    }
    return 0;
}