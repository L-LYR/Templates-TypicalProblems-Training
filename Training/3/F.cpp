#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int n, cnt = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    while (!arr.empty())
    {
        ++cnt;
        int i = *arr.begin(), j = 0;
        arr.erase(arr.begin());
        while (j < arr.size())
            if (arr[j] % i == 0)
                arr.erase(arr.begin() + j);
            else
                ++j;
    }
    cout << cnt << endl;
    return 0;
}