#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int w;
    while (cin >> w)
    {
        if (w % 2 || w == 2)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}