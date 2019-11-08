#include <iostream>
using namespace std;
int main(void)
{
    int s, d;
    while (cin >> s >> d)
    {
        int sum = -1;
        //case 1: ssssdssssdss
        if (4 * s < d)
            sum = 10 * s - 2 * d;
        //case 2: sssddsssddss
        else if (3 * s < 2 * d)
            sum = 8 * s - 4 * d;
        //case 3: ssdddssdddss
        else if (2 * s < 3 * d)
            sum = 6 * s - 6 * d;
        //case 4: sddddsddddsd
        else if (s < 4 * d)
            sum = 3 * s - 9 * d;
        //case 5: dddddddddddd -> sum = -1 in default
        if (sum >= 0)
            cout << sum << endl;
        else
            cout << "Deficit" << endl;
    }
    return 0;
}