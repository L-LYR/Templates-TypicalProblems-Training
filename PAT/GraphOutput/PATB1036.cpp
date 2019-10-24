#include <iostream>
using namespace std;
int main(void)
{
    int n;
    char ch;
    cin >> n >> ch;
    for (int c = 0; c < n; ++c)
        cout << ch;
    cout << endl;
    for (int r = 1; r < (n - 1) / 2; ++r)
    {
        cout << ch;
        for (int c = 1; c < n - 1; ++c)
            cout << " ";
        cout << ch << endl;
    }
    for (int c = 0; c < n; ++c)
        cout << ch;
    cout << endl;
    return 0;
}