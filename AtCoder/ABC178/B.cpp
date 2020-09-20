#include <algorithm>
#include <iostream>
using namespace std;

int main(void)
{
    long long a, b, c, d;
    long long ans;
    cin >> a >> b >> c >> d;

    if (b > 0 && d > 0)
        ans = max(b * d, a * c);
    else if (b <= 0 && d <= 0)
        ans = a * c;
    else if (b > 0 && d <= 0)
        ans = max(a * d, a * c);
    else if (b <= 0 && d > 0)
        ans = max(c * b, c * a);
    cout << ans << endl;
    return 0;
}