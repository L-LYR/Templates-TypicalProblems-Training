#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int next, cur = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> next;
        if (cur > next) {
            ans += 4 * (cur - next);
        } else {
            ans += 6 * (next - cur);
        }
        cur = next;
        ans += 5;
    }
    cout << ans << endl;

    return 0;
}