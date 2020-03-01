#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    while (--n >= 0)
    {
        string input;
        cin >> input;
        int len = input.length();
        if (len <= 10)
            cout << input << endl;
        else
            cout << input.front()
                 << len - 2
                 << input.back() << endl;
    }
    return 0;
}