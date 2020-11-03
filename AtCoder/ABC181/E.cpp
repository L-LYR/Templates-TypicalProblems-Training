#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int h[maxn], w[maxn];
int l[maxn], r[maxn];  // sum of left side and right side

int main(void) {
    int m, n;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> h[i];
    for (int i = 0; i < m; ++i) cin >> w[i];

    sort(h, h + n);
    sort(w, w + m);

    l[0] = r[n] = 0;
    for (int i = 2; i <= n; i += 2)
        l[i] = l[i - 2] + h[i - 1] - h[i - 2];

    for (int i = n - 2; i >= 0; i -= 2)
        r[i] = r[i + 2] + h[i + 1] - h[i];

    int ans = INT_MAX, p = 0;
    for (int i = 0; i < m; ++i) { 
        while (p < n && h[p] <= w[i]) p++;  // increasingly
        if (p % 2 == 0) {
            ans = min(ans, l[p] + r[p + 1] + h[p] - w[i]);
        } else {
            ans = min(ans, l[p - 1] + r[p] + w[i] - h[p - 1]);
        }
    }
    cout << ans << endl;
    return 0;
}
