#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 102;
struct step {
    int s, n, m, c;
    step(int _s, int _n, int _m, int _c)
        : s(_s), n(_n), m(_m), c(_c) {}
};
int S, N, M, t;
bool visited[maxn][maxn][maxn];
queue<step> qs;

int bfs() {
    memset(visited, 0, sizeof(visited));
    while (!qs.empty()) qs.pop();
    qs.push(step(S, 0, 0, 0));
    while (!qs.empty()) {
        step cur = qs.front();
        qs.pop();
        int cnt = 0;
        if (cur.m == t) cnt++;
        if (cur.n == t) cnt++;
        if (cur.s == t) cnt++;
        if (cnt == 2)
            return cur.c;
        else if (cnt > 0)
            return cur.c + 1;
        int det, ns, nn, nm;
        // N -> M
        det = min(M - cur.m, cur.n);
        ns = cur.s;
        nn = cur.n - det;
        nm = cur.m + det;
        if (!visited[ns][nn][nm]) {
            visited[ns][nn][nm] = true;
            qs.push(step(ns, nn, nm, cur.c + 1));
        }
        // M -> N
        det = min(N - cur.n, cur.m);
        ns = cur.s;
        nn = cur.n + det;
        nm = cur.m - det;
        if (!visited[ns][nn][nm]) {
            visited[ns][nn][nm] = true;
            qs.push(step(ns, nn, nm, cur.c + 1));
        }
        // S -> N
        det = min(N - cur.n, cur.s);
        ns = cur.s - det;
        nn = cur.n + det;
        nm = cur.m;
        if (!visited[ns][nn][nm]) {
            visited[ns][nn][nm] = true;
            qs.push(step(ns, nn, nm, cur.c + 1));
        }
        // N -> S
        det = min(S - cur.s, cur.n);
        ns = cur.s + det;
        nn = cur.n - det;
        nm = cur.m;
        if (!visited[ns][nn][nm]) {
            visited[ns][nn][nm] = true;
            qs.push(step(ns, nn, nm, cur.c + 1));
        }
        // S -> M
        det = min(M - cur.m, cur.s);
        ns = cur.s - det;
        nn = cur.n;
        nm = cur.m + det;
        if (!visited[ns][nn][nm]) {
            visited[ns][nn][nm] = true;
            qs.push(step(ns, nn, nm, cur.c + 1));
        }
        // M -> S
        det = min(S - cur.s, cur.m);
        ns = cur.s + det;
        nn = cur.n;
        nm = cur.m - det;
        if (!visited[ns][nn][nm]) {
            visited[ns][nn][nm] = true;
            qs.push(step(ns, nn, nm, cur.c + 1));
        }
    }
    return -1;
}

int main(void) {
    while (true) {
        cin >> S >> N >> M;
        if (S == 0) break;
        if (S % 2 == 1) {
            cout << "NO" << endl;
            continue;
        }
        t = S / 2;
        int ans = bfs();
        if (ans == -1)
            cout << "NO" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}