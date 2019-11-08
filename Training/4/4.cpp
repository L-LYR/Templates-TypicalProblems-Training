#include <iostream>
#include <queue>
#include <map>
using namespace std;

#define inCol(c) (c >= 0 && c < m)
#define inRow(r) (r >= 0 && r < n)
#define canMove(c) (c != '#')

const int maxn = 305;
char puzzle[maxn][maxn];
bool visited[maxn][maxn];

int n, m, depth = -1;

struct co
{
    int x, y;
    co(int _x = 0, int _y = 0) { x = _x, y = _y; }
    friend bool operator<(const co &a, const co &b)
    {
        if (a.x < b.x)
            return true;
        else if (a.x > b.x)
            return false;
        else
            return a.y < b.y;
    }
};
co s;
map<co, co> tp;

int d[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void input(void)
{
    map<char, co> tmp;
    cin >> n >> m;
    getchar();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            puzzle[i][j] = getchar();
            if (isalpha(puzzle[i][j]))
            {
                co temp = {i, j};
                if (tmp.count(puzzle[i][j]))
                {
                    tp.insert(make_pair(temp, tmp[puzzle[i][j]]));
                    tp.insert(make_pair(tmp[puzzle[i][j]], temp));
                }
                else
                    tmp.insert({puzzle[i][j], temp});
            }
            else if (puzzle[i][j] == '@')
                s = {i, j};
        }
        getchar();
    }
}

void bfs(void)
{
    int r, c;
    queue<co> q;
    q.push(s);
    visited[s.x][s.y] = true;
    while (!q.empty())
    {
        ++depth;
        int ql = q.size();
        for (int i = 0; i < ql; ++i)
        {
            auto tmp = q.front();
            q.pop();
            r = tmp.x;
            c = tmp.y;
            if (puzzle[r][c] == '=')
                return;
            else if (isalpha(puzzle[r][c]) && tp.count({r, c}) == 1)
            {
                r = tp[tmp].x;
                c = tp[tmp].y;
            }

            for (int j = 0; j < 4; ++j)
            {
                int x = r + d[j][0], y = c + d[j][1];
                if (inRow(x) && inCol(y) && canMove(puzzle[x][y]) && !visited[x][y])
                {
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
    }
}

int main(void)
{
    input();

    bfs();

    cout << depth << endl;

    return 0;
}