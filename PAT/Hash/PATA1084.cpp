#include <algorithm>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void)
{
    set<char> sc;
    string str, ws;
    cin >> str >> ws;
    int i = 0, j = 0;

    while (i < str.length())
    {
        if (str[i] != ws[j])
        {
            char c = toupper(str[i]);
            if (sc.count(c) == 0)
            {
                cout << c;
                sc.insert(c);
            }
        }
        else
            j++;
        i++;
    }
    cout << endl;
    return 0;
}