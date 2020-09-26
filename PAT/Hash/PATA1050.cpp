#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(void)
{
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    set<char> s(s2.begin(), s2.end());

    string ans;

    for (auto i : s1)
    {
        if (s.count(i))
            continue;
        ans.push_back(i);
    }
    cout << ans << endl;

    return 0;
}