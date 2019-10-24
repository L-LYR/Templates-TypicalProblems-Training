#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 300005;
int a[maxn];
int main(void)
{
    long long sum = 0;
    int n, m, q;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> q;
        cout << sum - a[n - q] << endl;
    }
    return 0;
}