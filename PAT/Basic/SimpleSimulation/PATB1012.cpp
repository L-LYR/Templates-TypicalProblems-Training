#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int a[5];
int main(void)
{
    int n, num, mod;
    int k = 1, cnt = 0, m = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> num;
        mod = num % 5;
        switch (mod)
        {
        case 0:
            if (!(num % 2))
                a[mod] += num;
            break;
        case 1:
            a[mod] += k * num;
            k = -k;
            ++m;
            break;
        case 2:
            ++a[mod];
            break;
        case 3:
            a[mod] += num;
            ++cnt;
            break;
        case 4:
            a[mod] = max(a[mod], num);
            break;
        }
    }
    if (a[0])
        cout << a[0] << " ";
    else
        cout << "N ";
    if (a[1] == 0 && m == 0)
        cout << "N ";
    else
        cout << a[1] << " ";
    if (a[2])
        cout << a[2] << " ";
    else
        cout << "N ";
    if (a[3])
        cout << fixed << setprecision(1) << a[3] / (double)cnt << " ";
    else
        cout << "N ";
    if (a[4])
        cout << a[4];
    else
        cout << "N" << endl;

    return 0;
}