#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 150005;
int arr[maxn];
int cnt[maxn];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr, arr + n);
    //from small to big
    //a[i]-1 a[i] a[i]+1
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == 1)
        {
            if (cnt[1] == 0)
                cnt[1]++;
            else
                cnt[2]++;
        }
        else
        {
            if (cnt[arr[i] - 1] == 0)
                cnt[arr[i] - 1]++;
            else if (cnt[arr[i]] == 0)
                cnt[arr[i]]++;
            else
                cnt[arr[i] + 1]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < maxn; ++i)
        if (cnt[i])
            ans++;
    cout << ans << endl;
    return 0;
}