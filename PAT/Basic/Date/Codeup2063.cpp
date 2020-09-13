#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<int> nonleap = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> leap = {
    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<vector<int>> month({nonleap, leap});
//judge whether it is leap
bool isLeap(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main(void)
{
    int N, y, m, d, inc;
    cin >> N;
    while (--N >= 0)
    {
        cin >> y >> m >> d >> inc;
        int flag = isLeap(y);
        while (inc > 0)
        {
            d++;
            if (d == month[flag][m] + 1)
            {
                m++;
                d = 1;
            }
            if (m == 13)
            {
                y++;
                flag = isLeap(y); //reminber to modify
                m = 1;
            }
            --inc;
        }
        cout << setw(4) << setfill('0') << y << '-'
             << setw(2) << setfill('0') << m << '-'
             << setw(2) << setfill('0') << d << endl;
    }
}