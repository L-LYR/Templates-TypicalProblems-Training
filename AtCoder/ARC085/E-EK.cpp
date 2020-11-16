#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
const int maxm = 5005;
const int maxn = 105;
const ll inf = INT_MAX;

int n, s, t;
ll gem[maxn];
int pre[maxn];  // the previous node of node i in flow s->t
ll flow[maxn];  // flow
vector<int> g[maxn];
ll cap[maxn][maxn];
ll ans;

bool bfs() {
    memset(pre, -1, sizeof(pre));
    queue<int> q;
    q.push(s);
    flow[s] = inf;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == t) break;
        for (auto i : g[cur]) {
            ll vol = cap[cur][i];
            if (vol > 0 && pre[i] == -1) {
                flow[i] = min(flow[cur], vol);
                pre[i] = cur;
                q.push(i);
            }
        }
    }
    return pre[t] != -1;
}

void update() {
    for (int i = t; i != s; i = pre[i]) {
        cap[i][pre[i]] += flow[t];
        cap[pre[i]][i] -= flow[t];
    }
    ans -= flow[t];
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

    while (bfs()) update();
    cout << ans << endl;
    return 0;
}
