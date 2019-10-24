#include <iostream>
#include <string>
using namespace std;
int a[30];
string guest, residence, pile;
int main(void)
{
    cin >> guest >> residence >> pile;
    int len = pile.length(), i;
    for (i = 0; i < len; ++i)
        a[pile[i] - 'A']++;
    len = guest.length();
    for (i = 0; i < len; ++i)
        a[guest[i] - 'A']--;
    len = residence.length();
    for (i = 0; i < len; ++i)
        a[residence[i] - 'A']--;
    for (i = 0; i < 26; ++i)
        if (a[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    cout << "YES" << endl;

    return 0;
}