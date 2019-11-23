#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;
const int maxn = 55;
int pies[maxn];
long long dp[maxn][2];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> pies[i];
    dp[n][1] = pies[n];
    for (int i = n - 1; i >= 1; --i)
    {
        dp[i][1] = max(dp[i + 1][1], dp[i + 1][0] + pies[i]);
        dp[i][0] = min(dp[i + 1][1], dp[i + 1][0] + pies[i]);
    }
    cout << dp[1][0] << " " << dp[1][1] << endl;
    return 0;
}