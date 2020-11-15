#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
int g[maxn][maxn];
bool visited[maxn];
int n, k, ans;

void dfs(int cur = 1, int dep = 0, int w = 0) {
    if (dep == n) {
        if (cur == 1 && w == k) ans++;
        return;
    }
    if (dep == n - 1) {
        dfs(1, dep + 1, w + g[cur][1]);
        return;
    }
    for (int i = 2; i <= n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, dep + 1, w + g[cur][i]);
            visited[i] = false;
        }
    }
}

int main(void) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> g[i][j];
        }
    }
    visited[1] = true;
    dfs();
    cout << ans << endl;
    return 0;
}