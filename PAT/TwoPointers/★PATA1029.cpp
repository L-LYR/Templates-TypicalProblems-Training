#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, m;
    scanf("%d", &n);
    vector<long> a(n);
    for (int i = 0; i < n; ++i) {
        scanf("%ld", &a[i]);
    }
    scanf("%d", &m);
    vector<long> b(m);
    for (int i = 0; i < m; ++i) {
        scanf("%ld", &b[i]);
    }

    int k = (m + n) / 2;
    if ((m + n) % 2) k++;

    int l = max(0, k - m), r = min(k, n);
    while (l < r) {
        int mid = (l + r) / 2;
        if (b[k - mid - 1] > a[mid]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    if (l == 0)
        cout << b[k - l - 1];
    else if (l == k)
        cout << a[l - 1];
    else
        cout << max(a[l - 1], b[k - l - 1]);
    cout << endl;

    return 0;
}