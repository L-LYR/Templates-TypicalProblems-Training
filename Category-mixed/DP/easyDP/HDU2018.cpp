#include <iostream>
using namespace std;

#define MAX 56
long long dp[MAX];

int main(void)
{
    for (int i = 1; i <= 3; ++i)
        dp[i] = i;
    for (int i = 4; i < MAX; ++i)
        dp[i] = dp[i - 1] + dp[i - 3];
    int N;
    while (cin >> N && N != 0)
        cout << dp[N] << endl;
    return 0;
}