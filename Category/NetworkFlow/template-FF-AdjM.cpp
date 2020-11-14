#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
using ll = long long;
const int maxm = 5005;
const int maxn = 205;
const int inf = 0x3f3f3f3f;

int n, m, s, t;
bool visited[maxn];  // the previous node of node i in flow s->t
ll flow[maxn];       // flow
vector<int> g[maxn];
ll cap[maxn][maxn];

ll dfs(int p = s, ll flow = inf) {
    if (p == t) return flow;
    visited[p] = true;
    for (auto v : g[p]) {
        ll vol = cap[p][v];
        if (vol <= 0 || visited[v]) continue;
        ll c;
        if ((c = dfs(v, min(vol, flow))) != -1) {
            cap[p][v] -= c;
            cap[v][p] += c;
            return c;
        }
    }
    return -1;
}

ll FF() {
    ll maxflow = 0, c;
    while ((c = dfs()) != -1) {
        memset(visited, false, sizeof(visited));
        maxflow += c;
    }
    return maxflow;
}

int main(void) {
    cin >> n >> m >> s >> t;
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        g[u].push_back(v);
        g[v].push_back(u);
        cap[u][v] += w;
    }
    cout << FF() << endl;
    return 0;
}
