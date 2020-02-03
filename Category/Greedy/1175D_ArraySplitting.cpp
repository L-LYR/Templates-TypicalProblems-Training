#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 300005;
int arr[maxn];
int main(void)
{
    int k, n;
    cin >> n >> k;
    for (int i = n - 1; i >= 0; --i)
        cin >> arr[i];

    long long cost = 0, last = 0;
    int flag = -1;
    while (k > 1)
    {
        long long curSum = 0, maxSum = INT64_MIN;
        for (int i = flag + 1; i <= n - k; ++i)
        {
            curSum += arr[i];
            if (curSum >= maxSum)
            {
                maxSum = curSum;
                flag = i;
            }
        }
        cost += maxSum + last;
        last += maxSum;
        --k;
    }
    cost += last;
    for (int i = flag + 1; i < n; ++i)
        cost += arr[i];

    cout << cost << endl;
    return 0;
}
