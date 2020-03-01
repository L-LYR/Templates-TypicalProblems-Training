#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
ll dp[maxn][2];
// dp[i][0]
// when it was counted up to i sentences, number of cases
// which came from AC
// dp[i][1]
// just came from RJ
ll sum[maxn];
int main(void)
{
    int x, nq, l, r;
    scanf("%d%d", &x, &nq);
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i < maxn; ++i)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        if (i >= x)
            dp[i][1] = dp[i - x][0]; // no continuous AC
    }

    for (int i = 1; i < maxn; ++i) // prefix sum
    {
        sum[i] = (dp[i][0] + dp[i][1]) % mod;
        sum[i] = (sum[i] + sum[i - 1]) % mod;
    }

    for (int i = 0; i < nq; ++i) // query
    {
        scanf("%d%d", &l, &r);
        printf("%lld\n", (sum[r] - sum[l - 1] + mod) % mod);
    }

    return 0;
}