#include <iostream>
#include <algorithm>
using namespace std;
long long mod = 1000000007;
#define MAX 1000001
long long dp[MAX][3];

long long DP(long long N, long long M, long long K)
{
    long long sum;
    dp[0][0] = 1;
    dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= N; ++i)
    {
        sum = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;

        dp[i][0] = sum;

        if (i <= K)
            dp[i][1] = sum;
        else if (i == K + 1)
            dp[i][1] = sum - 1;
        else
            dp[i][1] = (sum - dp[i - K - 1][0] - dp[i - K - 1][2]) % mod;

        if (i <= M)
            dp[i][2] = sum;
        else if (i == M + 1)
            dp[i][2] = sum - 1;
        else
            dp[i][2] = (sum - dp[i - M - 1][0] - dp[i - M - 1][1]) % mod;
        // cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
    }

    return (dp[N][0] + dp[N][1] + dp[N][2]) % mod;
}

int main(void)
{
    long long N, M, K;
    while (cin >> N >> M >> K)
        cout << ((DP(N, N, K) - DP(N, M - 1, K)) % mod + mod) % mod << endl;
    // (|a-c|%b)==((a-c)%b+b)%b
    return 0;
}