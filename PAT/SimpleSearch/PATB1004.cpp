#include <iostream>
#include <string>
#include <map>
using namespace std;
map<int, string> db;
int main(void)
{
    int n, mark;
    string name, id, info;
    cin >> n;
    while (--n >= 0)
    {
        cin >> name >> id >> mark;
        info = name + " " + id;
        db.insert(make_pair(mark, info));
    }
    cout << db.rbegin()->second << endl;
    cout << db.begin()->second << endl;

    return 0;
}