// Reference: https://www.luogu.com.cn/problemnew/solution/CF360B
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 2005;
int n, k;
int arr[maxn];

bool judge(long long  c)
{
    // dp[j] means the minimum change-times in the interval [1, j].
    // The value scale should be [- c * (j - i), c * (j - i)].
    // if dp[i] + j - i, where j - i means change i + 1, i + 2,..., j,
    // is less than dp[j], we will make dp[j] equal to it.
    int dp[maxn];

    for (int i = 1; i <= n; ++i)
        dp[i] = i - 1;

    for (int j = 2; j <= n; ++j)
    {
        for (int i = 1; i < j; ++i)
        {
            if (abs(arr[j] - arr[i]) <= c * (j - i))
                dp[j] = min(dp[j], dp[i] + j - i - 1);
        }
    }

    for (int i = 1; i <= n; ++i)
        if (dp[i] + n - i <= k)
            return true;

    return false;
}

int main(void)
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];

    int max_diff = 0, diff;
    for (int i = 1; i < n; ++i)
    {
        diff = abs(arr[i + 1] - arr[i]);
        max_diff = max(diff, max_diff);
    }
    // Important!!
    // It is impossible to enumerate all change-cases,
    // so we have to find the value of minimum of c(a)
    // by using binary search.

    int left = 0, right = max_diff;
    while (left < right)
    {
        int mid = left + ((right - left) >> 1);
        if (judge(mid))
            right = mid;
        else
            left = mid + 1;
    }
    cout << left << endl;
    return 0;
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i < n; ++i)
    // {
    //     cout << diff[i] << " ";
    // }
    // cout << endl;
}