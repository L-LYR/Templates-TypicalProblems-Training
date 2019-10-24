#include <bits/stdc++.h>
using namespace std;

bool find(list<pair<char, char>> &c, pair<char, char> &target)
{
    for (auto i = c.begin(); i != c.end(); ++i)
        if (*i == target)
        {
            // cout << "remove " << i->first << " " << i->second << endl;
            c.erase(i);
            return true;
        }
    return false;
}
int main(void)
{
    // ofstream fileout("output.txt", ios::out);
    // streambuf *backupout = cout.rdbuf();
    // cout.rdbuf(fileout.rdbuf());

    // ifstream filein("input.txt", ios::in);
    // streambuf *backupin = cin.rdbuf();
    // cin.rdbuf(filein.rdbuf());
    // int count = 1;
    string in;
    while (cin >> in)
    {
        string cube = in.substr(0, 6);
        list<pair<char, char>> c;
        for (int i = 0; i < 3; ++i)
            c.push_back({cube[i], cube[5 - i]});
        // for (auto j : c)
        // cout << j.first << " " << j.second << endl;
        cube = in.substr(6, 6);
        int flag = 0, rotate = 0;
        pair<char, char> target;
        for (int i = 0; i < 3; ++i)
        {
            target = make_pair(cube[i], cube[5 - i]);
            if (find(c, target))
                ++flag;
            else
            {
                target = make_pair(cube[5 - i], cube[i]);
                if (find(c, target))
                {
                    ++flag;
                    // ++rotate;
                }
            }
            // for (auto j : c)
            // cout << j.first << " " << j.second << endl;
        }
        // cout << count++;
        if (flag == 3 && !(rotate % 2))
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }

    // cout.rdbuf(backupout);
    // fileout.close();

    // cin.rdbuf(backupin);
    // filein.close();
    return 0;
}