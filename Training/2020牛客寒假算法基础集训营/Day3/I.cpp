#include <iostream>
#include <map>
using namespace std;
// A->B,A->C,B->A,B->C,C->A,C->B
//  0    1    2    3    4    5
const int maxn = 65;
long long dp[maxn][7];
int main(void)
{
    int n;
    scanf("%d", &n);
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][2];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][3] + 1;
        dp[i][2] = dp[i - 1][4] + dp[i - 1][0];
        dp[i][3] = dp[i - 1][5] + dp[i - 1][1];
        dp[i][4] = dp[i - 1][2] + dp[i - 1][5];
        dp[i][5] = dp[i - 1][3] + dp[i - 1][4];
    }
    printf("A->B:%lld\n", dp[n][0]);
    printf("A->C:%lld\n", dp[n][1]);
    printf("B->A:%lld\n", dp[n][2]);
    printf("B->C:%lld\n", dp[n][3]);
    printf("C->A:%lld\n", dp[n][4]);
    printf("C->B:%lld\n", dp[n][5]);
    printf("SUM:%lld\n", dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] + dp[n][5]);

    return 0;
}