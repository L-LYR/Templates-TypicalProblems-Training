#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(void)
{
    int N, M;
    string num, info, q, temp;
    cin >> N;
    while (--N >= 0)
    {
        map<string, string> db;
        cin >> M;
        while (--M >= 0)
        {
            cin >> num;
            info.clear();
            cin >> info;
            for (int i = 0; i < 2; ++i)
            {
                cin >> temp;
                info += " " + temp;
            }
            db.insert(make_pair(num, info));
        }
        cin >> q;
        if (db.count(q))
            cout << q << " " << db[q] << endl;
        else
            cout << "No Answer!" << endl;
    }
    return 0;
}