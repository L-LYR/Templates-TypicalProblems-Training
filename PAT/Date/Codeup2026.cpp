#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
vector<int> nonleap = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
    int y, m, d;
    int N;
    cin >> N;
    while (--N >= 0)
    {
        cin >> y >> m >> d;
        ++d;
        if (d == nonleap[m] + 1)
        {
            d = 1;
            m++;
        }
        if (m == 13)
        {
            y++;
            m = 1;
        }
        cout << setw(4) << setfill('0') << y << '-'
             << setw(2) << setfill('0') << m << '-'
             << setw(2) << setfill('0') << d << endl;
    }
    return 0;
}