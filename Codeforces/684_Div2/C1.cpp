#include <bits/stdc++.h>
using namespace std;
const auto maxn = 105;

auto solve(const vector<string>& b, int n, int m) -> void {
    auto ans = 0;
    for (const auto& s : b)
        ans += count_if(s.begin(), s.end(), [](char c) { return c == '1'; });
    cout << 3 * ans << endl;
    for (auto i = 0; i < n; i++) {
        for (auto j = 0; j < m; j++) {
            int ki = 1, kj = 1;
            if (i == n - 1) ki = -1;
            if (j == m - 1) kj = -1;
            if (b[i][j] == '1') {
                // For each '1' cell we do the following operations:
                //  Opt1: [][]  Opt2: []    Opt3: [][]
                //        []          [][]          []
                // The turned-over times of each cell are [3][2] .
                //                                      [2][2]
                // For cases that the cell is at the edge of the board, just rotate
                // the operations above.
                // So the '1' cell will be turned over and the rest aren't changed.
                // Because the number of cells is no more than n*m,
                // the maximum number of operations is no more than 3*n*m.

                printf("%d %d %d %d %d %d\n", i + 1, j + 1, i + 1 + ki, j + 1, i + 1, j + 1 + kj);
                printf("%d %d %d %d %d %d\n", i + 1, j + 1, i + 1 + ki, j + 1, i + 1 + ki, j + 1 + kj);
                printf("%d %d %d %d %d %d\n", i + 1, j + 1, i + 1, j + 1 + kj, i + 1 + ki, j + 1 + kj);
            }
        }
    }
}

auto main(void) -> int {
    auto t = 0, n = 0, m = 0;
    cin >> t;
    auto b = vector<string>(maxn);
    while (t-- > 0) {
        cin >> n >> m;
        b.resize(n);
        for (auto& s : b) cin >> s;
        solve(b, n, m);
    }
    return 0;
}