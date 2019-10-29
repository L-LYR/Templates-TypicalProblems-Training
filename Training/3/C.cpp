#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int b[maxn];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    sort(b, b + n);
    long long sum = 0;
    for (int i = 0; i < n; ++i)
        sum += b[i] * (n - i);
    cout << sum << endl;
    return 0;
}