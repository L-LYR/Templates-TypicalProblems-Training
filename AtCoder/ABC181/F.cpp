#include <bits/stdc++.h>

using namespace std;
const int maxn = 105;
const double eps = 1e-12;
int n;
int x[maxn], y[maxn], f[maxn];
int find(int u) { return f[u] == u ? u : (f[u] = find(f[u])); }
void merge(int u, int v) {
    int fu = find(u), fv = find(v);
    if (fu != fv) f[fv] = fu;
}
void init() {
    for (int i = 0; i <= n + 2; ++i) {
        f[i] = i;
    }
}
double dis(int i, int j) {
    int dx = x[i] - x[j];
    int dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
}
bool check(double d) {
    init();
	// if in the circle, merge
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (dis(i, j) <= d) merge(i, j);
        }
    }
	// n + 1: y = 100
	// n + 2: y = -100
    for (int i = 1; i <= n; ++i) {
        if (abs(y[i] - 100) <= d) merge(i, n + 1);
        if (abs(y[i] + 100) <= d) merge(i, n + 2);
    }
	// there must be divided into two parts
    return find(n + 1) != find(n + 2);
}

int main(void) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    double l = 0, r = 100; // enumerate the radius by bisection
    while (r - l >= eps) {
        double m = (r + l) / 2;
        if (check(2 * m))
            l = m;
        else
            r = m;
    }
    printf("%lf\n", l);
    return 0;
}
