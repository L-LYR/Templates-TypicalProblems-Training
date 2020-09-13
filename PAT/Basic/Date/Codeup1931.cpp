#include <iostream>
#include <vector>
#include <iomanip>
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
    int m, y, t;
    while (cin >> y >> t)
    {
        int all = 0, flag = isLeap(y);
        for (m = 1; t > month[flag][m]; ++m)
            t -= month[flag][m];
        cout << setw(4) << setfill('0') << y << '-'
             << setw(2) << setfill('0') << m << '-'
             << setw(2) << setfill('0') << t << endl;
    }
    return 0;
}