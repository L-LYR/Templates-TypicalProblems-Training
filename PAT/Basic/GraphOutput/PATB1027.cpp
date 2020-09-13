#include <iostream>
using namespace std;
int main(void)
{
    int n, use = 1;
    char ch;
    cin >> n >> ch;
    int i = 3;
    while (n - use >= 0)
    {
        use += i * 2;
        i = i + 2;
    }
    i -= 4;
    use -= 2 * i + 4;
    for (int j = 0; j <= i / 2; ++j)
    {
        for (int k = 0; k < j; ++k)
            cout << " ";
        for (int k = 0; k < (i - j * 2); ++k)
            cout << ch;
        cout << endl;
    }
    for (int j = 1; j <= i / 2; ++j)
    {
        for (int k = 0; k < i / 2 - j; ++k)
            cout << " ";
        for (int k = 0; k < 2 * j + 1; ++k)
            cout << ch;
        cout << endl;
    }
    cout << n - use << endl;
    return 0;
}