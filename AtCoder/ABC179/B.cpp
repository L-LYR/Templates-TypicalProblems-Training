#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int D[maxn][2];
int n;

int main(void) {
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> D[i][0] >> D[i][1];

    for (int i = 0; i < n - 2; ++i) {
        bool e1 = D[i][0] == D[i][1];
        bool e2 = D[i + 1][0] == D[i + 1][1];
        bool e3 = D[i + 2][0] == D[i + 2][1];
        if (e1 && e2 && e3) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}