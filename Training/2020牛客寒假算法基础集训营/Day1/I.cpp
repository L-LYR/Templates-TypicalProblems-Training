#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
const int maxn = 300005;
ll dp[maxn];
ll n, a, b, c;
string str;
const string a_str = "nico",
             b_str = "niconi",
             c_str = "niconiconi";
int main(void)
{
    cin >> n >> a >> b >> c;
    cin >> str;

    for (int i = 4; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        if (i >= 4 && str.substr(i - 4, 4) == a_str)
            dp[i] = max(dp[i], dp[i - 4] + a);
        if (i >= 6 && str.substr(i - 6, 6) == b_str)
            dp[i] = max(dp[i], dp[i - 6] + b);
        if (i >= 10 && str.substr(i - 10, 10) == c_str)
            dp[i] = max(dp[i], dp[i - 10] + c);
    }
    cout << dp[n] << endl;

    return 0;
}