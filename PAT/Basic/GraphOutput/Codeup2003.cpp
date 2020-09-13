#include <iostream>
using namespace std;
int main(void)
{
    int n, h;
    cin >> n;
    while (--n >= 0)
    {
        cin >> h;
        int maxLen = 3 * h - 2;
        for (int i = 0; i < h; ++i)
        {
            int len = 2 * i + h, lim = h - i - 1;
            string a(lim, ' '), b(len, '*');
            cout << a << b << endl;
        }
    }
    return 0;
}