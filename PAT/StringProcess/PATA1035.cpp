#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct account
{
    string name;
    string password;
};

map<char, char> bind = {
    {'1', '@'},
    {'0', '%'},
    {'l', 'L'},
    {'O', 'o'},
};

bool modify(account &acc)
{
    bool ret = false;
    for (int i = 0; i < acc.password.length(); ++i)
        if (bind.count(acc.password[i]))
        {
            acc.password[i] = bind[acc.password[i]];
            ret = true;
        }
    return ret;
}

int main(void)
{
    int n;
    cin >> n;
    account l[n];
    vector<account> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i].name >> l[i].password;
        if (modify(l[i]))
            ans.push_back(l[i]);
    }
    if (ans.size() == 0)
    {
        if (n == 1)
            cout << "There is " << n
                 << " account and no account is modified" << endl;
        else
            cout << "There are " << n
                 << " accounts and no account is modified" << endl;
    }
    else
    {
        cout << ans.size() << endl;
        for (auto i : ans)
            cout << i.name << " " << i.password << endl;
    }

    return 0;
}