#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 1001
int arr[MAXN][MAXN];
int dp[MAXN][MAXN];

int main(void)
{
    int N;
    cin >> N;
    while (--N >= 0)
    {
        int i, j, k;    
        cin >> i;
        for (j = 1; j <= i; ++j)
            for (k = 1; k <= j; ++k)
                cin >> arr[j][k];
        for (k = 1; k <= i; ++k)
            dp[i][k] = arr[i][k];
        for (j = i - 1; j > 0; --j)
            for (k = 1; k <= j; ++k)
                dp[j][k] = arr[j][k] + max(dp[j + 1][k], dp[j + 1][k + 1]);
        cout << dp[1][1] << endl;
    }
    return 0;
}