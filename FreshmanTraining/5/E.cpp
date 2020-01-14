#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int c, d, n, m, k;
    cin >> c >> d >> n >> m >> k;
    int target = n * m - k;
    if (target < 0)
    {
        cout << 0 << endl;
        return 0;
    }
    int upper = ceil(target / (double)n);
    int minp = INT32_MAX;
    for (int i = 0; i <= upper; ++i)
    {
        int j = target - n * i, cur = c * i;
        if (j > 0)
            cur += d * j;
        minp = min(minp, cur);
    }
    cout << minp << endl;
    return 0;
}