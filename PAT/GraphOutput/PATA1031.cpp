#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string str;
    cin >> str;
    int len = str.length();
    int v, h, cnt = 0, rcnt = len - 1;
    for (h = 3; h <= len; ++h)
        if (!((len - h + 2) % 2))
        {
            v = (len - h + 2) / 2;
            if (v <= h)
                break;
        }
    for (int i = 0; i < v - 1; ++i)
    {
        cout << str[cnt++];
        for (int j = 1; j < h - 1; ++j)
            cout << " ";
        cout << str[rcnt--] << endl;
    }
    for (int k = cnt; k <= rcnt; ++k)
        cout << str[k];
    cout << endl;
    return 0;
}