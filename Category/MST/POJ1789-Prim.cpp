#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 2001;
int n, g[maxn][maxn], d[maxn];
bool vis[maxn];
char truck[maxn][8];
int dis(char *s, char *t) {
    int ans = 0;
    for (int k = 0; k < 7; k++)
        if (s[k] != t[k]) ans++;
    return ans;
}
int prim() {
    memset(d, 0x3f, sizeof(d));
    memset(vis, false, sizeof(vis));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int me = -1;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && (me == -1 || d[me] > d[j])) me = j;
        vis[me] = true;
        if (i) ans += d[me];
        for (int j = 1; j <= n; j++) d[j] = min(d[j], g[me][j]);
    }
    return ans;
}
int main() {
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 1; i <= n; i++) scanf("%s", truck[i]);
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                g[i][j] = g[j][i] = dis(truck[i], truck[j]);
            }
        }
        printf("The highest possible quality is 1/%d.\n", prim());
    }
    return 0;
}