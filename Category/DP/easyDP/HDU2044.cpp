#include <iostream>
using namespace std;

#define MAX 50
long long dp[MAX];

int main(void)
{
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < MAX; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    int N, b, e;
    cin >> N;
    while (--N >= 0)
    {
        cin >> b >> e;
        cout << dp[e - b] << endl;
    }
    return 0;
}