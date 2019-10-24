#include <iostream>
using namespace std;
int main(void)
{
    int a = 0, b = 0, N;
    int x, y, p, q;
    bool fa, fb;
    cin >> N;
    while (--N >= 0)
    {
        fa = fb = false;
        cin >> x >> y >> p >> q;
        if (x + p == y)
            fa = true;
        if (x + p == q)
            fb = true;
        if (fa && !fb)
            ++a;
        if (!fa && fb)
            ++b;
    }
    cout << b << " " << a << endl;
    return 0;
}