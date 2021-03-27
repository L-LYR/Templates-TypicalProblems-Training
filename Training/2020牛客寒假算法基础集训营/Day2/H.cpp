#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn], dp[maxn];
int main(void)
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++)
    {
        if (i < 2 * k)
            dp[i] = a[i] - a[1];
        else
            dp[i] = min(dp[i - 1] + a[i] - a[i - 1],
                        dp[i - k] + a[i] - a[i - k + 1]);
    }
    printf("%d\n", dp[n]);
    return 0;
}