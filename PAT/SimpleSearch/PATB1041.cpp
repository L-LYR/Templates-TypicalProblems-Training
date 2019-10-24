#include <iostream>
#include <map>
#include <string>
using namespace std;
map<int, string> db;
int main(void)
{
    int N, M, num, s;
    string id;
    cin >> N;
    while (--N >= 0)
    {
        cin >> id >> num >> s;
        id += " " + to_string(s);
        db.insert(make_pair(num, id));
    }
    cin >> M;
    while (--M >= 0)
    {
        cin >> num;
        cout << db[num] << endl;
    }
    return 0;
}