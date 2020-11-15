#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int n;
ll w;
ll cur[maxn];

int main(void) {
    cin >> n >> w;
    int s, t, p;
    int lim = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s >> t >> p;
        cur[s] += p;
        cur[t] += -p;
        lim = max(lim, t);
    }

    for (int i = 1; i <= lim; ++i) cur[i] += cur[i - 1];
    for (int i = 0; i <= lim; ++i) {
        if (cur[i] > w) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}