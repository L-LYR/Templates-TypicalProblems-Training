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

int n, s, t;
ll gem[maxn];
bool visited[maxn];  // the previous node of node i in flow s->t
ll flow[maxn];       // flow
vector<int> g[maxn];
ll cap[maxn][maxn];
ll ans;

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
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> gem[i];
    }
    s = n + 1;
    t = n + 2;
    for (int i = 1; i <= n; ++i) {
        if (gem[i] < 0) {
            cap[s][i] = -gem[i];
            g[s].push_back(i);
            g[i].push_back(s);
        } else {
            cap[i][t] = gem[i];
            g[i].push_back(t);
            g[t].push_back(i);
            ans += gem[i];
        }

        for (int j = 2 * i; j <= n; j += i) {
            cap[i][j] = inf;
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
    cout << ans - FF() << endl;
    return 0;
}
