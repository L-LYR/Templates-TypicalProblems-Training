#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

int main(void)
{
    string buf, temp;
    set<string> dictionary;
    while (cin >> buf)
    {
        for (auto i = buf.begin(); i != buf.end(); ++i)
        {
            if (isalpha(*i))
                *i = tolower(*i);
            else
                *i = '\n';
        }
        stringstream strin(buf);
        while (strin >> temp)
            dictionary.insert(temp);
    }

    for (auto j = dictionary.begin(); j != dictionary.end(); ++j)
        cout << *j << endl;
    return 0;
}