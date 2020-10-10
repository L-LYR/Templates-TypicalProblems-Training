#include <bits/stdc++.h>
using namespace std;
int main(void) {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    int sz = n * 2;
    vector<int> id(sz + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        if (a[i] != -1 && b[i] != -1) {
            if (a[i] >= b[i]) {  // invalid record
                cout << "No" << endl;
                return 0;
            }
        }
        if (a[i] != -1) {
            if (id[a[i]] != 0) {  // conflict
                cout << "No" << endl;
                return 0;
            }
            id[a[i]] = i;
        }
        if (b[i] != -1) {
            if (id[b[i]] != 0) {  // conflict
                cout << "No" << endl;
                return 0;
            }
            id[b[i]] = -i;
        }
    }

    // If a interval [x, x + k + i] is valid, there must be a sequence:
    // (x, x + i) (x + 1, x + 1 + i) ... (x + k, x + k + i)
    // the left element means this person is on at this floor,
    // the right element means this person is off at this floor.

    // 1. the length of the interval must be even
    // 2. [x, x + (k + i) / 2] [x + (k + i) / 2 + 1, x + k + i] are supplementary

    vector<bool> dp(sz + 1, false);
    dp[0] = true;

    for (int r = 2; r <= sz; r += 2) {  // [1, r]
        bool cur = false;
        for (int l = 0; l < r && !cur; l += 2) {  // two parts [1, l] [l + 1, r]
                                                  // check(1 + l, r)
            bool flag = true;
            int half = (r - l) / 2;
            for (int k = l + 1; k <= r && flag; ++k) {
                if (id[k] < 0 && a[-id[k]] != -1 && a[-id[k]] < 1 + l) flag = false;  // on too early
                if (id[k] > 0 && b[id[k]] != -1 && b[id[k]] > r) flag = false;        // off too late
            }
            for (int k = l + 1; k < l + 1 + half && flag; ++k) {
                if (id[k] < 0) flag = false;                                                  // the left-side one is off
                if (id[k + half] > 0) flag = false;                                           // the right-side one is on
                if (id[k + half] != 0 && id[k] != 0 && id[k + half] != -id[k]) flag = false;  // not the same person
            }
            cur = cur || (flag && dp[l]);
        }
        dp[r] = cur;
    }

    if (dp[sz])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}