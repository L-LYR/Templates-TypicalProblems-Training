#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    int n;
    cin >> n;
    map<int, string> signIn, signOut;
    string id;
    int h, m, s, temp;
    while (--n >= 0)
    {
        cin >> id;
        cin >> h;
        cin.ignore(1) >> m;
        cin.ignore(1) >> s;
        temp = h * 10000 + m * 100 + s;
        signIn.insert(make_pair(temp, id));
        cin >> h;
        cin.ignore(1) >> m;
        cin.ignore(1) >> s;
        temp = h * 10000 + m * 100 + s;
        signOut.insert(make_pair(temp, id));
    }
    cout << signIn.begin()->second << " "
         << signOut.rbegin()->second << endl;
    return 0;
}