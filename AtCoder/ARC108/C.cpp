#include <bits/stdc++.h>
using namespace std;
const auto maxn = int(1e5 + 5);
struct edge {
    int to, c, next;
    edge(int v, int tag, int nxt)
        : to(v), c(tag), next(nxt) {}
};
auto ans = vector<int>(maxn, -1);
auto visited = vector<bool>(maxn, false);
auto es = vector<edge>();
auto head = vector<int>(maxn, -1);
auto color = 1;
auto n = 0, m = 0;
// greedy algorithm
// If the parent vertex has the same tag with the current edge,
// the current vertex chooses another tag.
// If the parent vertex has a different tag from the current edge,
// the current vertex chooses the same tag with the current edge.
// This algorithm just uses DFS to traverse all the vertice.
void dfs(int p, int e, int u) {
    if (ans[p] != e) {
        ans[u] = e;
    } else {
        while (color == e) {
            color++;
            if (color > n) color = 1;
        }
        ans[u] = color++;
    }
    for (auto v = head[u]; v != -1; v = es[v].next) {
        if (!visited[es[v].to]) {
            visited[es[v].to] = true;
            dfs(u, es[v].c, es[v].to);
        }
    }
}

auto main() -> int {
    cin >> n >> m;
    auto u = 0, v = 0, c = 0, cnt = 0;
    for (auto i = 0; i < m; ++i) {
        cin >> u >> v >> c;
        es.emplace_back(v, c, head[u]);
        head[u] = cnt++;
        es.emplace_back(u, c, head[v]);
        head[v] = cnt++;
    }
    visited[1] = true;
    dfs(0, -1, 1);

    for (auto i = 1; i <= n; ++i)
        cout << ans[i] << endl;

    return 0;
}