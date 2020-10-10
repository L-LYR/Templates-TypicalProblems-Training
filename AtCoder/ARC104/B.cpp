#include <bits/stdc++.h>
using namespace std;

// int main(void) {
//     int n;
//     cin >> n;
//     char ch;
//     int at[n + 1], cg[n + 1];
//     at[0] = cg[0] = 0;
//     for (int i = 1; i <= n; ++i) {
//         cin >> ch;
//         if (ch == 'A') {
//             at[i] = at[i - 1] + 1;
//             cg[i] = cg[i - 1];
//         } else if (ch == 'T') {
//             at[i] = at[i - 1] - 1;
//             cg[i] = cg[i - 1];
//         } else if (ch == 'C') {
//             at[i] = at[i - 1];
//             cg[i] = cg[i - 1] + 1;
//         } else if (ch == 'G') {
//             at[i] = at[i - 1];
//             cg[i] = cg[i - 1] - 1;
//         }
//     }
//     int ans = 0;
//     for (int i = 0; i < n; ++i) {
//         for (int j = i + 1; j < n; ++j) {
//             int atc = at[j + 1] - at[i];
//             int cgc = cg[j + 1] - cg[i];
//             if (atc == 0 && cgc == 0) {
//                 ans++;
//             }
//         }
//     }
//     cout << ans << endl;

//     return 0;
// }

int main(void) {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int c1 = 0, c2 = 0;
        for (int j = i; j < N; ++j) {
            if (S[j] == 'A')
                c1++;
            else if (S[j] == 'T')
                c1--;
            else if (S[j] == 'C')
                c2++;
            else
                c2--;
            if (c1 == 0 && c2 == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}