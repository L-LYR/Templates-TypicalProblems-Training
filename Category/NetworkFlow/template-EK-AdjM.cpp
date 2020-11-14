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
int pre[maxn];  // the previous node of node i in flow s->t
ll flow[maxn];  // flow
vector<int> g[maxn];
ll cap[maxn][maxn];

bool bfs() {
    memset(pre, -1, sizeof(pre));
    queue<int> q;
    q.push(s);
    flow[s] = inf;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto i : g[cur]) {
            ll vol = cap[cur][i];
            if (vol > 0 && pre[i] == -1) {
                flow[i] = min(flow[cur], vol);
                pre[i] = cur;
                q.push(i);
                if (i == t) break;
            }
        }
    }
    return pre[t] != -1;
}

ll EK() {
    ll ans = 0;
    while (bfs()) {
        for (int i = t; i != s; i = pre[i]) {
            cap[i][pre[i]] += flow[t];
            cap[pre[i]][i] -= flow[t];
        }
        ans += flow[t];
    }
    return ans;
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
    cout << EK() << endl;
    return 0;
}
