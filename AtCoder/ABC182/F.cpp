#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> f, g;

// target:
// a sequence: x[n]
// satisfy:
// |    |    A[i+1]           
// |x[n]| < -------- 
// |    |     A[i]
//    n
//  \sum A[i] * x[i] == X
//   i=1
int main(void) {
    auto n = 0ll, x = 0ll;
    cin >> n >> x;
    auto a = vector<long long>(n + 1);
    for (int i = n; i > 0; --i) cin >> a[i];

    auto x0 = x / a[1] * a[1];
    f[x0] = 1;
    // if x0 != x, x is not a multiple of a[1].
    if (x0 != x) f[x0 + a[1]] = 1;
    
    for (int i = 2; i <= n; ++i) {
        // the maximum number of a[i]
        auto mx = a[i - 1] / a[i];
        for (auto k : f) {
            auto d = x - k.first;
            auto m = d / a[i];
            auto y = k.first + m * a[i];
            if (abs(m) < mx)
                g[y] += k.second;
            if (y != x and abs(m) + 1 < mx)
                g[y + a[i] * (d / abs(d))] += k.second;
        }
        f.swap(g);
        g.clear();
    }
    cout << f[x] << endl;
    return 0;
}