#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    long long a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    cout << min(a, y) + min(b, z) << endl;
    return 0;
}