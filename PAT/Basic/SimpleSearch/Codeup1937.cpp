#include <iostream>
#include <set>
using namespace std;
int main(void)
{
    int n, k, m, b;
    while (cin >> n)
    {
        set<int> db;
        while (--n >= 0)
        {
            cin >> k;
            db.insert(k);
        }
        cin >> m;
        while (--m >= 0)
        {
            cin >> b;
            if (db.count(b))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}