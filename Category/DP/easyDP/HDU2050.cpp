#include <iostream>
using namespace std;
int main(void)
{
    int N;
    long long n;
    cin >> N;
    while (--N >= 0)
    {
        cin >> n;
        cout << n * (2 * n - 1) + 1 << endl;
    }
    return 0;
}