#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int m, i, j;
    cin >> m;
    string tmp[m + 1];
    for (i = 1; i <= m; ++i)
    {
        cin >> tmp[i];
        for (j = 1; j < 4 && j < i; ++j)
            cout << j << '=' << tmp[i - j + 1] << " ";
        cout << j << '=' << tmp[i - j + 1] << endl;
    }

    return 0;
}