// Reference: https://www.cnblogs.com/birchtree/p/11239879.html
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 100005;
const int maxh = 105;
const int inf = 0xfffffff;
int height[maxn];
int dp[maxn][maxh];

int main(void)
{
    int n, c;
    scanf("%d %d", &n, &c);
    int maxheight = 0;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &height[i]);
        maxheight = max(maxheight, height[i]);
    }

    // initialize
    memset(dp, 0x3f, sizeof(dp));
    for (int h = height[1]; h <= maxheight; ++h)
        dp[1][h] = (h - height[1]) * (h - height[1]);

    for (int i = 2; i <= n; ++i) // from the second one
    {
        for (int h = height[i]; h <= maxheight; ++h) // [height[i], maxheight]
        {
            int last = inf;
            int quadratic = (height[i] - h) * (height[i] - h);
            for (int k = height[i - 1]; k <= maxheight; ++k)
            {
                int cur = dp[i - 1][k] + c * abs(k - h) + quadratic;
                dp[i][h] = min(dp[i][h], cur);

                // dp[i][h] = min(dp[i][h], dp[i - 1][k] + c * |k - h| + (height[i] - h) ^ 2)
                if (cur > last) // The left side of the equation is an even function of k.
                    break;      // When it becomes bigger, it have reached the minimum already.
                last = cur;
            }
        }
    }

    int ans = inf;
    for (int h = height[n]; h <= maxheight; ++h)
        ans = min(dp[n][h], ans);
    cout << ans << endl;

    return 0;
}