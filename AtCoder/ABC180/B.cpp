#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<long long> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    long long m = 0;
    long double e = 0;
    long long q = 0;
    for (int i = 0; i < n; ++i) {
        long long absq = llabs(p[i]);
        m += absq;
        e += powf64x(p[i], 2);
        if (absq > q) q = absq;
    }
    cout << m << endl
         << fixed << setprecision(15)<< sqrt(e) << endl
         << q << endl;

    return 0;
}