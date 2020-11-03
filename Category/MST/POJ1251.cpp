#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 27;
const int inf = 0x3f3f3f3f;
struct edge {
    int from, to;
    int weight;
    edge(int u = -1, int v = -1, int w = inf)
        : from(u), to(v), weight(w) {}
    bool operator<(const edge& r) {
        if (weight != r.weight)
            return weight < r.weight;
        else if (from != r.from)
            return from < r.from;
        else
            return to < r.to;
    }
};
struct DisjointSet {
    vector<int> f;  // father node
    vector<int> r;  // node rank

    DisjointSet(int n = 0) {
        f.resize(n);
        for (int i = 0; i < n; ++i) {
            f[i] = i;
        }
        r.resize(n, 0);
    }

    int find(int u) { return f[u] == u ? u : (f[u] = find(f[u])); }

    void merge(int u, int v) {
        int fu = find(u), fv = find(v);
        if (r[fu] > r[fv]) {
            f[fv] = fu;
        } else {
            f[fu] = fv;
            if (r[fu] == r[fv]) ++r[fv];
        }
    }
    bool isJoint(int u, int v) {
        int fu = find(u), fv = find(v);
        return fu == fv;
    }
};

int main(void) {
    int n;
    while (1) {
        cin >> n;
        if (n == 0) break;
        int k, d;
        char c, t;
        vector<edge> edges;
        for (int i = 1; i < n; ++i) {
            cin >> c >> k;
            for (int j = 0; j < k; ++j) {
                cin >> t >> d;
                edges.push_back(edge(c - 'A', t - 'A', d));
                edges.push_back(edge(t - 'A', c - 'A', d));
            }
        }

        DisjointSet ds(n);
        int ans = 0;
        sort(edges.begin(), edges.end());
        for (int i = 0; i < edges.size(); ++i) {
            if (ds.isJoint(edges[i].from, edges[i].to)) continue;
            ds.merge(edges[i].from, edges[i].to);
            ans += edges[i].weight;
        }

        cout << ans << endl;
    }

    return 0;
}
