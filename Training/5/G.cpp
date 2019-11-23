#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
long long mod = 1000000007;
long long dp[105], mdp[105];
int main(void)
{
    int n, k, d;
    cin >> n >> k >> d;
    dp[0] = 0;
    for (int i = 1; i <= k; ++i)
        dp[i] = (accumulate(dp, dp + i, 0ll) % mod + 1) % mod;
    for (int i = k + 1; i <= n; ++i)
        dp[i] = accumulate(dp + i - k, dp + i, 0ll) % mod;
    mdp[0] = 0;
    --d;
    for (int i = 1; i <= d; ++i)
        mdp[i] = (accumulate(mdp, mdp + i, 0ll) % mod + 1) % mod;
    for (int i = d + 1; i <= n; ++i)
        mdp[i] = accumulate(mdp + i - d, mdp + i, 0ll) % mod;
    // for (int i = 0; i <= n; ++i)
    //     cout << dp[i] << " ";
    // cout << endl;
    // for (int i = 0; i <= n; ++i)
    //     cout << mdp[i] << " ";
    cout << (dp[n] - mdp[n] + mod) % mod << endl;
    return 0;
}