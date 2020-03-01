#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxn = 1e5 + 5;
int main(void)
{
    int n;
    double sum = 0;
    scanf("%d", &n);
    for (int i = 0, a; i < n; ++i)
    {
        scanf("%d", &a);
        sum += a;
    }
    double x = (sum - 90 * n) / (sum - 81 * n) * 100;
    printf("%0.2lf%%\n", x);
    return 0;
}