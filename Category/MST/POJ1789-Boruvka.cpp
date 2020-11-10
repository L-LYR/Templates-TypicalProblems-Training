#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
const int maxn = 2001;
const int inf = 0x3f3f3f3f;

int n, tol;
int f[maxn];
char truck[maxn][8];
int u[maxn * maxn],
    v[maxn * maxn],
    w[maxn * maxn];
bool used[maxn * maxn];
int best[maxn];

int find(int u) { return (f[u] == u) ? u : (f[u] = find(f[u])); }

int weight(char* l, char* r) {
    int d = 0;
    for (int k = 0; k < 8; ++k)
        if (l[k] != r[k]) d++;
    return d;
}

int boruvka() {
    int ans = 0;
    int nt = n;
    while (nt > 1) {
        memset(best, -1, sizeof(best));
        for (int i = 0; i < tol; ++i) {
            if (used[i]) continue;
            int pu = find(u[i]);
            int pv = find(v[i]);
            if (pu == pv) continue;
            if (best[pu] == -1 || w[i] < w[best[pu]]) best[pu] = i;
            if (best[pv] == -1 || w[i] < w[best[pv]]) best[pv] = i;
        }
        for (int i = 1; i <= n; ++i) {
            int cur = best[i];
            if (cur == -1) continue;
            if (used[cur]) continue;
            used[cur] = true;
            ans += w[cur];
            nt--;
            f[find(u[cur])] = f[find(v[cur])];
        }
    }
    return ans;
}

int main(void) {
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        memset(used, false, sizeof(used));
        for (int i = 1; i <= n; ++i) {
            scanf("%s", truck[i]);
            f[i] = i;
        }
        tol = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                u[tol] = i;
                v[tol] = j;
                w[tol] = weight(truck[i], truck[j]);
                tol++;
            }
        }
        printf("The highest possible quality is 1/%d.\n", boruvka());
    }
    return 0;
}