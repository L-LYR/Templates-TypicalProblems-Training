#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 100;
int n, m;
int a, b, w[maxn], v[maxn]; //c is the weight while d is the value
int num[maxn];              //number of stuffing
int dp[20005];
int main(void)
{
    cin >> n >> m >> w[0] >> v[0];
    num[0] = n / w[0]; //floor
    for (int i = 1; i <= m; ++i)
    {
        cin >> a >> b >> w[i] >> v[i];
        num[i] = min(a / b, n / w[i]); //floor
    }
    //multi-bag
    for (int i = 0; i <= m; ++i) //m stuffings
    {
        for (int j = n; j > 0; --j) //dough from max to 0
        {
            for (int k = 0; k <= num[i]; ++k) //for the max number of stuffing[i]
            {
                if (j - k * w[i] >= 0)
                {
                    dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
                }
            }
        }
    }
    int maxv = 0;
    for (auto i : dp)
    {
        maxv = max(i, maxv);
    }
    cout << maxv << endl;
    return 0;
}