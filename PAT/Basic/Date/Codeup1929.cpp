#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
vector<string> month{"", "January", "February", "March", "April", "May", "June",
                     "July", "August", "September", "October", "November", "December"};
vector<string> day{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int main(void)
{
    map<string, int> mdmap;
    for (int i = 1; i <= 12; ++i)
        mdmap[month[i]] = i;
    int d, y, m;
    string M;
    while (cin >> d >> M >> y)
    {
        m = mdmap[M];
        if (m == 1 || m == 2)
        {
            m += 12;
            y--;
        }
        //to get the date under Gregorian style of dating
        int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
        cout << day[iWeek] << endl;
    }
    return 0;
}