#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>
char lo[3] = {'W', 'T', 'L'};
using namespace std;
int main(void)
{
    double sum = 1.0, in;
    for (int i = 0; i < 3; ++i)
    {
        map<double, char> db;
        for (int j = 0; j < 3; ++j)
        {
            cin >> in;
            db.insert(make_pair(in, lo[j]));
        }
        sum *= db.rbegin()->first;
        cout << db.rbegin()->second << " ";
    }
    cout << fixed << setprecision(2)
         << sum * 1.3 - 2 << endl;
    return 0;
}