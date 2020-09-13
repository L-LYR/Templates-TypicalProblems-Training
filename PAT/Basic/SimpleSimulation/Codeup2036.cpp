#include <iostream>
using namespace std;
int main(void)
{
    int n, k;
    while (cin >> n)
    {
        int o = 0, e = 0;
        while (--n >= 0)
        {
            cin >> k;
            k % 2 ? ++o : ++e;
        }
        cout << ((e > o) ? "NO" : "YES") << endl;
    }
    return 0;
}