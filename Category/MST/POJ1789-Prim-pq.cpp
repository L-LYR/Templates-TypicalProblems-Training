#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
const int maxn = 2001;
int n, g[maxn][maxn], d[maxn];
bool vis[maxn];
char truck[maxn][8];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii> > q;
int dis(char *s, char *t) {
    int ans = 0;
    for (int k = 0; k < 7; k++)
        if (s[k] != t[k]) ans++;
    return ans;
}
int prim() {
    while (!q.empty()) q.pop();
    q.push(make_pair(0, 1));
    memset(d, 0x3f, sizeof(d));
    memset(vis, false, sizeof(vis));

    int ans = 0, cnt = 0;
    while (cnt < n) {
        while (!q.empty() && vis[q.top().second]) q.pop();
        if (q.empty()) break;
        int u = q.top().second;
        ans += q.top().first;
        cnt++;
        q.pop();
        vis[u] = true;
        for (int j = 1; j <= n; j++) {
            if (g[u][j] < d[j]) {
                d[j] = g[u][j];
                q.push(make_pair(d[j], j));
            }
        }
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