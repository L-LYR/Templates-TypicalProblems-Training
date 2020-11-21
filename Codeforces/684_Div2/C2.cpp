#include <bits/stdc++.h>
using namespace std;
const auto maxn = 105;

typedef pair<int, int> point;
#define x first
#define y second

struct step {
    point a, b, c;
};

auto opp = map<char, char>({{'0', '1'}, {'1', '0'}});

auto solve(vector<string>& b, int n, int m) -> void {
    auto ans = vector<step>();
    auto shapeL = [&](int x, int y) {
        b[x][y] = '0';
        b[x + 1][y] = opp[b[x + 1][y]];
        auto ky = (y == m - 1) ? -1 : 1;
        b[x + 1][y + ky] = opp[b[x + 1][y + ky]];
        ans.push_back({{x + 1, y + 1}, {x + 2, y + 1}, {x + 2, y + 1 + ky}});
    };

    // handle the [0, n - 2) rows
    for (auto i = 0; i < n - 2; ++i)
        for (auto j = 0; j < m; ++j)
            if (b[i][j] == '1') shapeL(i, j);

    // handle the [n - 2, n) two rows
    for (int j = 0; j < m - 1; ++j) {
        if (b[n - 1][j] == '1' and b[n - 2][j] == '1') {
            shapeL(n - 2, j);
        } else if (b[n - 1][j] == '1') {
            b[n - 1][j] = '0';
            b[n - 2][j + 1] = opp[b[n - 2][j + 1]];
            b[n - 1][j + 1] = opp[b[n - 1][j + 1]];
            ans.push_back({{n, j + 1}, {n, j + 2}, {n - 1, j + 2}});
        } else if (b[n - 2][j] == '1') {
            b[n - 2][j] = '0';
            b[n - 2][j + 1] = opp[b[n - 2][j + 1]];
            b[n - 1][j + 1] = opp[b[n - 1][j + 1]];
            ans.push_back({{n - 1, j + 1}, {n - 1, j + 2}, {n, j + 2}});
        }
    }

    // push all the '1' to the last two cell
    // handle the last two cells
    if (b[n - 1][m - 1] == '1' and b[n - 2][m - 1] == '1') {
        ans.push_back({{n, m}, {n - 1, m - 1}, {n, m - 1}});
        ans.push_back({{n - 1, m}, {n - 1, m - 1}, {n, m - 1}});
    } else if (b[n - 1][m - 1] == '1') {
        ans.push_back({{n, m}, {n - 1, m}, {n, m - 1}});
        ans.push_back({{n, m}, {n - 1, m - 1}, {n, m - 1}});
        ans.push_back({{n, m}, {n - 1, m - 1}, {n - 1, m}});
    } else if (b[n - 2][m - 1] == '1') {
        ans.push_back({{n - 1, m}, {n, m}, {n - 1, m - 1}});
        ans.push_back({{n - 1, m}, {n - 1, m - 1}, {n, m - 1}});
        ans.push_back({{n - 1, m}, {n, m}, {n, m - 1}});
    }
    cout << ans.size() << endl;
    for (const auto& s : ans)
        printf("%d %d %d %d %d %d\n", s.a.x, s.a.y, s.b.x, s.b.y, s.c.x, s.c.y);
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