#include <iostream>
#include <cmath>
using namespace std;
const int maxn = 25000000;
const int offset = 12500000;
short leftVal[maxn];

int a[6], x[6];

int main(void)
{
    for (int i = 1; i <= 5; ++i)
        cin >> a[i];

    for (x[1] = -50; x[1] <= 50; ++x[1])
        if (x[1] != 0)
            for (x[2] = -50; x[2] <= 50; ++x[2])
                if (x[2] != 0)
                {
                    int val = pow(x[1], 3) * a[1] + pow(x[2], 3) * a[2];
                    val += offset;
                    leftVal[val]++;
                }

    int ans = 0;

    for (x[3] = -50; x[3] <= 50; ++x[3])
        if (x[3] != 0)
            for (x[4] = -50; x[4] <= 50; ++x[4])
                if (x[4] != 0)
                    for (x[5] = -50; x[5] <= 50; ++x[5])
                        if (x[5] != 0)
                        {
                            int val = 0;
                            for (int i = 3; i <= 5; ++i)
                                val += pow(x[i], 3) * a[i];
                            val += offset;
                            if (val >= 0 && val < maxn)
                                ans += leftVal[val];
                        }
    cout << ans << endl;
    return 0;
}