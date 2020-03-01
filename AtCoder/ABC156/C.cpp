#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
int x[maxn];
int n;
int cal(int p)
{
    int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += (x[i] - p) * (x[i] - p);
    return sum;
}
int main(void)
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &x[i]);
    int l = 0, r = 105;
    while (l < r)
    {
        int m = (l + r) >> 1;
        int rm = (m + r) >> 1;
        if (cal(m) > cal(rm))
            l = m;
        else
            r = rm;
    }
    printf("%d\n", cal(l + 1));
    return 0;
}