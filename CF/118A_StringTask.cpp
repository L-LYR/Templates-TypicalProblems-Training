#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    string input, target;
    while (cin >> input)
    {
        target.clear();
        int len = input.length();
        for (int i = 0; i < len; ++i)
        {
            input[i] = towlower(input[i]);
            switch (input[i])
            {
            case 'a':
            case 'o':
            case 'y':
            case 'e':
            case 'u':
            case 'i':
                continue;
            default:
                target.push_back('.');
                target.push_back(input[i]);
            }
        }
        cout << target << endl;
    }
    return 0;
}