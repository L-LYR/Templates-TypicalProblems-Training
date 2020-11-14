#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 205;
const int maxm = 5005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct edge {
    int to, next;
    ll vol;
};

int n, m, s, t;
int head[maxn], now[maxn], level[maxn];
edge es[maxm << 1];
int tol;

void init() {
    tol = 1;
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, ll w) {
    tol++;
    es[tol].to = v;
    es[tol].vol = w;
    es[tol].next = head[u];
    head[u] = tol;
}

bool bfs() {
    memset(level, -1, sizeof(level));

    queue<int> q;
    q.push(s);
    level[s] = 0;
    now[s] = head[s];

    int v;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = head[cur]; i != -1; i = es[i].next) {
            v = es[i].to;
            if (level[v] == -1 && es[i].vol > 0) {
                now[v] = head[v];
                level[v] = level[cur] + 1;
                q.push(v);
                if (v == t) return true;
            }
        }
    }
    return false;
}

ll dfs(int cur = s, ll curflow = inf) {
    if (cur == t) return curflow;
    ll remain = curflow, outflow, vol;
    int v;
    for (int i = now[cur]; i != -1 && remain > 0; i = es[i].next) {
        now[cur] = i;
        v = es[i].to;
        vol = es[i].vol;
        if (vol > 0 && level[v] == level[cur] + 1) {
            outflow = dfs(v, min(vol, remain));
            if (outflow == 0) level[v] = -1;
            remain -= outflow;
            es[i].vol -= outflow;
            es[i ^ 1].vol += outflow;
        }
    }
    return curflow - remain;
}

ll dinic() {
    ll ans = 0;
    while (bfs()) ans += dfs();
    return ans;
}

int main(void) {
    init();
    int u, v;
    ll w;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%lld", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, 0);
    }
    printf("%lld\n", dinic());
    return 0;
}