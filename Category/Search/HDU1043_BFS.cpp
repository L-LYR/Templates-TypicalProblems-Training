// Time: 03/24/21
// Author: HammerLi
// Tags: [Search] [BFS]
#include <bits/stdc++.h>
using namespace std;

string target(9, 0), start = "12345678x";
unordered_map<string, string> memo;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char d[] = "durl";  // this must be reversed.

auto BFS() -> void {
    queue<string> q;
    q.push(start);
    string cur, cur_ops;
    int loc, x, y, nloc, nx, ny;
    while (!q.empty()) {
        cur = q.front();
        cur_ops = memo[cur];
        q.pop();

        loc = cur.find('x');
        x = loc / 3;
        y = loc % 3;

        for (int i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            nloc = nx * 3 + ny;
            swap(cur[loc], cur[nloc]);
            if (!memo.count(cur)) {
                memo[cur] = d[i] + cur_ops;
                q.push(cur);
            }
            swap(cur[loc], cur[nloc]);
        }
    }
}

auto main(void) -> int {
    BFS();
    while (cin >> target[0]) {
        for (int i = 1; i < 9; ++i) cin >> target[i];
        if (memo.count(target)) {
            cout << memo[target] << endl;
        } else {
            cout << "unsolvable\n";
        }
    }
    return 0;
}