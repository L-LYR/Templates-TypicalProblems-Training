#include <iostream>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    int maxLen = 2 * n - 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
            cout << " ";
        for (int j = 0; j < maxLen - 2 * i; ++j)
            cout << (((j % 2) == 0) ? "*" : " ");
        cout << endl;
    }
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
            cout << " ";
        for (int j = 0; j < maxLen - 2 * i; ++j)
            cout << (((j % 2) == 0) ? "*" : " ");
        cout << endl;
    }
    return 0;
}