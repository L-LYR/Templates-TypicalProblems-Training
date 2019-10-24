#include <iostream>
#include <iomanip>
using namespace std;
int main(void)
{
    int C1, C2;
    cin >> C1 >> C2;
    int d = (int)((C2 - C1) / 100.0 + 0.5);
    int h = d / 3600;
    d -= h * 3600;
    int m = d / 60;
    d -= m * 60;
    int s = d;
    cout << setw(2) << setfill('0') << h << ':'
         << setw(2) << setfill('0') << m << ':'
         << setw(2) << setfill('0') << s << endl;
    return 0;
}