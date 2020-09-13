#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        string a, b;
        cin >> a >> b;
        if (a.length() == b.length())
            cout << a << " is equal long to " << b << endl;
        else if (a.length() > b.length())
            cout << a << " is longer than " << b << endl;
        else
            cout << a << " is shorter than " << b << endl;
    }
    return 0;
}