#include <iostream>
using namespace std;
const int maxn = 1005;
int d[maxn];
int main(void)
{
    int n, k, flag;
    while (cin >> n >> k)
    {
        flag = 1;
        for (int i = 0; i <= k; ++i)
        {
            cin >> d[i];
            if (d[i] > n) //importent!
                flag = 0;
        }
        int sum = 0, cnt = 0;
        for (int i = 0; i <= k; ++i)
        {
            if (sum + d[i] > n)
            {
                sum = d[i];
                ++cnt;
            }
            else
                sum += d[i];
        }
        if (flag)
            cout << cnt << endl;
        else
            cout << "No Solution!" << endl;
    }
    return 0;
}