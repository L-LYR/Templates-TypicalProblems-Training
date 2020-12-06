#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e3 + 5;
int t, n, m;
int f[maxn];
void init(int n) {
    for (int i = 0; i <= n; ++i) f[i] = i;
}
int find(int u) { return (f[u] == u) ? u : (f[u] = find(f[u])); }

int main(void) {
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d %d", &n, &m);
        init(n);
        int A, B;
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", &A, &B);
            f[find(A)] = f[find(B)];
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            if (f[i] == i) ans++;
        printf("%d\n", ans);
    }

    return 0;
}