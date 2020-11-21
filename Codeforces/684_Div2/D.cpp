#include <bits/stdc++.h>
using namespace std;
#define deg first
#define id second

const auto maxn = int(1e5 + 5);

inline auto FastIO() -> void {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

auto g = vector<vector<int>>(maxn);
auto degree = vector<int>(maxn);
auto visited = vector<bool>(maxn);
auto drop = vector<bool>(maxn);
auto clique = vector<int>(maxn);
auto subset = vector<int>(maxn);
auto n = 0, m = 0, k = 0;
auto ans = -1;

auto preprocess() -> void {
    cin >> n >> m >> k;
    for (auto i = 1; i <= n; ++i) {
        g[i].clear();
        degree[i] = 0;
        drop[i] = visited[i] = false;
    }
    auto x = 0, y = 0;
    for (auto i = 0; i < m; ++i) {
        cin >> x >> y;
        degree[x]++;
        degree[y]++;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    for (auto i = 1; i <= n; ++i)
        sort(g[i].begin(), g[i].end());
}
auto solve() -> void {
    // If there exists a clique,
    // the number of edges is greater than
    // or equal to k * (k - 1) / 2.
    if (1ll * k * (k - 1) > 2 * m) {
        ans = -1;
        return;
    }
    auto q = queue<int>();
    // if the degree of the vertex is less than k,
    // it will not belong to a subset.
    // we need to remove it from the graph.
    // if the degree of the vertex is equal to k,
    // it may belong to a clique, so we need to check it out
    // during the BFS.
    for (auto i = 1; i <= n; ++i) {
        if (degree[i] < k) {
            visited[i] = true;
            q.push(i);
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (degree[cur] == k - 1) {
            clique.clear();
            clique.emplace_back(cur);
            for (auto v : g[cur])
                if (!drop[v]) clique.emplace_back(v);
            if (clique.size() != k) break;
            bool isClique = true;
            for (auto u : clique) {
                for (auto v : clique) {
                    if (u == v) break;
                    if (!binary_search(g[u].begin(), g[u].end(), v))
                        isClique = false;
                }
            }
            if (isClique) {
                ans = 2;
                return;
            }
        }

        drop[cur] = true;  // remove the current vertex
        for (auto v : g[cur]) {
            --degree[v];  // update the degrees
            if (degree[v] < k && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    // after removing all impossible vertice,
    // find the target subset in the unvisited vertice.
    ans = -1;
    subset.clear();
    for (auto i = 1; i <= n; ++i) {
        if (!visited[i]) {
            subset.push_back(i);
            ans = 1;
        }
    }
}

auto print = [](int x) { cout << " " << x; };
auto printAns() -> void {
    if (ans == -1) {
        cout << -1 << endl;
    } else if (ans == 1) {
        cout << ans << " " << subset.size() << endl;
        cout << subset.front();
        for_each(next(subset.begin()), subset.end(), print);
        cout << endl;
    } else if (ans == 2) {
        cout << ans << endl;
        cout << clique.front();
        for_each(next(clique.begin()), clique.end(), print);
        cout << endl;
    }
}

auto main() -> int {
    FastIO();
    auto t = 0;
    cin >> t;
    while (t-- > 0) {
        preprocess();
        solve();
        printAns();
    }
    return 0;
}