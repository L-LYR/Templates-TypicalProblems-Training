#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, y, m, d, cnt = 0;
    long long b, maxVal = 18140905, minVal = 20140907;
    cin >> n;
    //date compare
    string name, maxPer, minPer;
    while (--n >= 0)
    {
        cin >> name;
        cin >> y;
        cin.ignore(1) >> m;
        cin.ignore(1) >> d;
        b = 10000 * y + 100 * m + d;
        if (b >= 18140906 && b <= 20140906)
        {
            if (b > maxVal)
            {
                maxVal = b;
                maxPer = name;
            }
            if (b < minVal)
            {
                minVal = b;
                minPer = name;
            }
            ++cnt;
        }
    }
    if (!cnt)
        cout << 0 << endl;
    else
        cout << cnt << " " << minPer << " " << maxPer << endl;
    return 0;
}