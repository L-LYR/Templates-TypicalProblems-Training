#include <iostream>
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
    int a, b;
    while (cin >> a >> b)
    {
        if (a > b) //a is always the smaller one
            swap(a, b);
        int y1 = a / 10000, m1 = a % 10000 / 100, d1 = a % 100;
        int y2 = b / 10000, m2 = b % 10000 / 100, d2 = b % 100;
        int ans = 1, flag = isLeap(y1);
        while (y1 < y2 || m1 < m2 || d1 < d2)
        {
            d1++;
            if (d1 == month[flag][m1] + 1)
            {
                m1++;
                d1 = 1;
            }
            if (m1 == 13)
            {
                y1++;
                flag = isLeap(y1); //reminber to modify
                m1 = 1;
            }
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}