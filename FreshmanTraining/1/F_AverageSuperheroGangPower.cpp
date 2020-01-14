#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
const int maxn = 100005;
int a[maxn];

int main(void)
{
    long long n, k, m, sum = 0, inc;
    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    long double maxVal = 0;
    for (int i = 0; i <= min(m, n - 1); ++i)
    {
        if (i)
            sum -= a[i - 1];

        inc = min(k * (n - i), m - i);

        maxVal = max(maxVal, (long double)(sum + inc) / (long double)(n - i));
    }
    cout << fixed << setprecision(20) << maxVal << endl;
    return 0;
}