#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        string r, b;
        cin >> r >> b;
        int rc = 0, bc = 0;
        for (int i = 0; i < n; ++i) {
            if (r[i] > b[i]) rc++;
            else if (r[i] < b[i]) bc++;
        }
        if (rc > bc) cout << "RED" << endl;
        else if (rc < bc) cout << "BLUE" << endl;
        else cout << "EQUAL" << endl;
    }
    return 0;
}
