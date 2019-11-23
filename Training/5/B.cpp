#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 65;
long long dp[maxn];
int main(void)
{
    int n;
    cin >> n;
    dp[0] = dp[1] = 0;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
        dp[i] = dp[i - 2] * 2;

    cout << dp[n] << endl;
    return 0;
}