#include <iostream>
#include <cstring>
using namespace std;

int cash[6] = {100, 50, 20, 10, 5, 1};
int main(void)
{
    int n, m;
    while (cin >> n)
    {
        int cnt[6];
        memset(cnt, 0, sizeof(int) * 6);
        while (--n >= 0)
        {
            cin >> m;
            //from the greatest face value
            for (int i = 0; i < 6; ++i)
            {
                cnt[i] += m / cash[i];
                m %= cash[i];
            }
        }
        cout << cnt[0];
        for (int i = 1; i < 6; ++i)
            cout << " " << cnt[i];
        cout << endl;
    }
    return 0;
}