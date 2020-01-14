#include <iostream>
#include <queue>
using namespace std;

struct point
{
    int x, y;
    int d;
    friend bool operator==(const point &a, const point &b) { return a.x == b.x && a.y == b.y; }
};

const int maxn = 105;
int n, m;
int map[maxn][maxn];
bool visit[maxn][maxn][8];

int D[8][2] = {
    {-1, -1},
    {0, -1},
    {1, -1},
    {1, 0},
    {1, 1},
    {0, 1},
    {-1, 1},
    {-1, 0}};

int main(void)
{
    cin >> m >> n;
    for (int i = 1; i <= n; ++i)

        for (int j = 1; j <= m; ++j)

            cin >> map[i][j];
    point e = {n, m, -1};
    bool flag = false;
    queue<point> q;
    q.push({1, 1, -1});
    int pace = -1;
    while (!q.empty())
    {
        ++pace;
        int ql = q.size();
        for (int i = 0; i < ql; ++i)
        {
            auto cur = q.front();
            int x = cur.x, y = cur.y, c = cur.d;
            q.pop();
            if (cur == e)
            {
                flag = true;
                break;
            }
            for (int j = 0; j < 8; ++j)
            {
                if (j != c)
                {
                    int nx = x + map[x][y] * D[j][0];
                    int ny = y + map[x][y] * D[j][1];
                    if (nx > 0 && nx <= n && ny > 0 && ny <= m && !visit[nx][ny][j])
                    {
                        visit[nx][ny][j] = true;
                        q.push({nx, ny, j});
                        // cout << nx << " " << ny << endl;
                    }
                }
            }
        }
        if (flag)
            break;
    }
    if (flag)
        cout << pace << endl;
    else
        cout << "NEVER" << endl;
    return 0;
}