#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
const int maxn = 2005;
// ans[i][j]
// represents the probability of
// among the first i questions
// there are j question right.
ll p[maxn], ans[maxn][maxn];
int n;
int main(void)
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &p[i]);
    ans[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        ans[i][0] = ans[i - 1][0] * (mod + 1 - p[i]) % mod;
        for (int j = 1; j <= i; ++j)
            ans[i][j] = (ans[i - 1][j] * (mod + 1 - p[i]) + ans[i - 1][j - 1] * p[i]) % mod;
    }
    for (int i = 0; i <= n; ++i)
        cout << ans[n][i] << " ";
    return 0;
}