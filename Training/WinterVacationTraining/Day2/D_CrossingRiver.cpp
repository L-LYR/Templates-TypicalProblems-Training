#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        int n;
        cin >> n;
        vector<int> speed(n);
        for (int i = 0; i < n; ++i)
            cin >> speed[i];

        sort(speed.begin(), speed.end());
        //plan 1: fastest & sub-fastest go and fastest back
        //        then slowest & sub-slowest go and sub-fastest back
        //        speed[1] + speed[0] + speed[n] + speed[1]
        //plan 2: fastest & slowest go and fastest back
        //        then fastest & sub-slowest go and fastest back
        //        speed[n] + speed[0] + speed[n-1] + speed[0]
        int sum = 0;
        while (n)
        {
            if (n >= 4)
            {
                sum += min(speed[1] + speed[0] + speed[n - 1] + speed[1],
                           speed[n - 1] + speed[0] + speed[n - 2] + speed[0]);
                n -= 2;
            }
            else if (n == 3)
            {
                sum += speed[0] + speed[1] + speed[2];
                n -= 3;
            }
            else if (n == 2)
            {
                sum += max(speed[0], speed[1]);
                n -= 2;
            }
            else if (n == 1)
            {
                sum += speed[0];
                n -= 1;
            }
        }
        cout << sum << endl;
    }
}