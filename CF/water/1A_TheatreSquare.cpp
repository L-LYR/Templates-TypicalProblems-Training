#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    long long n, m, a;
    while (cin >> n >> m >> a)
    {
        n = n / a + ((n % a) ? 1 : 0);
        m = m / a + ((m % a) ? 1 : 0);
        cout << m * n << endl;
    }
    return 0;
}