#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    int ans = 0, l, r, cur, w = 1;

    while (n / w != 0) {
        l = n / (w * 10);
        cur = n / w % 10;
        r = n % w;
        if (cur == 0)
            ans += l * w;
        else if (cur == 1)
            ans += l * w + r + 1;
        else
            ans += (l + 1) * w;
        w *= 10;
    }
    cout << ans << endl;

    return 0;
}