#include <map>
#include <string>
#include <iostream>
using namespace std;
int main(void)
{
    map<int, string> F, M;
    string id, name;
    char gender;
    int mark, n;
    cin >> n;
    while (--n >= 0)
    {
        cin >> name >> gender >> id >> mark;
        name += " " + id;
        if (gender == 'F')
            F.insert(make_pair(mark, name));
        else
            M.insert(make_pair(mark, name));
    }
    if (F.empty())
        cout << "Absent" << endl;
    else
        cout << F.rbegin()->second << endl;
    if (M.empty())
        cout << "Absent" << endl;
    else
        cout << M.begin()->second << endl;
    if (M.empty() || F.empty())
        cout << "NA" << endl;
    else
        cout << F.rbegin()->first - M.begin()->first << endl;
    return 0;
}