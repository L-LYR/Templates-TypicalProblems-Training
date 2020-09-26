#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void)
{
    string ws, str;
    getline(cin, ws);
    getline(cin, str); // for empty input
    set<char> sc;
    bool noUpper = false;
    for (const auto &i : ws)
    {
        if (isalpha(i))
        {
            sc.insert(tolower(i));
            sc.insert(toupper(i));
        }
        else
            sc.insert(i);
        if (i == '+')
            noUpper = true;
    }

    for (const auto &i : str)
    {
        if (!(noUpper && isupper(i)) && sc.count(i) == 0)
            cout << i;
    }
    cout << endl;

    return 0;
}