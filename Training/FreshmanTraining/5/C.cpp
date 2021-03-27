#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 200005, mod = 1000000007;
long long dp[maxn][3];

int main(void)
{
    int n, l, r;
    cin >> n >> l >> r;
    int len = r - l + 1;
    vector<int> cnt(3, len / 3);
    if (len % 3 == 1)
        cnt[l % 3]++;
    else if (len % 3 == 2)
    {
        for (int i = 0; i < 3; ++i)
            cnt[i]++;
        cnt[(r + 1) % 3]--;
    }
    for (int i = 0; i < 3; ++i)
        dp[1][i] = cnt[i];
    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = ((dp[i - 1][0] * cnt[0]) % mod +
                    (dp[i - 1][1] * cnt[2]) % mod +
                    (dp[i - 1][2] * cnt[1]) % mod) %
                   mod;
        dp[i][1] = ((dp[i - 1][0] * cnt[1]) % mod +
                    (dp[i - 1][1] * cnt[0]) % mod +
                    (dp[i - 1][2] * cnt[2]) % mod) %
                   mod;
        dp[i][2] = ((dp[i - 1][0] * cnt[2]) % mod +
                    (dp[i - 1][1] * cnt[1]) % mod +
                    (dp[i - 1][2] * cnt[0]) % mod) %
                   mod;
    }
    cout << dp[n][0] << endl;
    return 0;
}