#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100005;
int nums[maxn];
long long dp[maxn][2];

int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    dp[0][1] = abs(nums[0] - 1);
    dp[0][0] = abs(nums[0] + 1);
    for (int i = 1; i < n; ++i)
    {
        dp[i][1] = min(dp[i - 1][1] + abs(nums[i] - 1),
                       dp[i - 1][0] + abs(nums[i] + 1));
        dp[i][0] = min(dp[i - 1][0] + abs(nums[i] - 1),
                       dp[i - 1][1] + abs(nums[i] + 1));
    }
    cout << dp[n - 1][1] << endl;
    return 0;
}