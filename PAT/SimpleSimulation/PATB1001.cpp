#include <iostream>
using namespace std;
int main(void)
{
    int n, step = 0;
    cin >> n;
    while (n > 1)
    {
        n = ((n % 2) ? (3 * n + 1) / 2 : n / 2);
        ++step;
    }
    cout << step << endl;
    return 0;
}