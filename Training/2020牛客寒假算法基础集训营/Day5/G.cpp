#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct node
{
    int x, y, t;
    node(int x_ = 0, int y_ = 0, int t_ = 0)
        : x(x_), y(y_), t(t_) {}
} start;
const int maxn = 505;
const int maxloop = 22;
int n, m, p, k, loop;
char maze[maxn][maxn];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool vis[maxn][maxn][maxloop];
bool zombie[maxn][maxn][maxloop];
char s[20];

int main(void)
{
    memset(vis, 0, sizeof(vis));
    memset(zombie, 0, sizeof(zombie));
    scanf("%d%d%d%d", &n, &m, &p, &k);
    loop = 2 * k - 2;
    for (int i = 1; i <= n; ++i)
        scanf("%s", maze[i] + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (maze[i][j] == 'L')
                start = {i, j, 0};

    for (int i = 0; i < p; ++i)
    {
        int x, y;
        scanf("%d%d%s", &x, &y, s);
        int d;
        if (s[0] == 'U')
            d = 0;
        else if (s[0] == 'D')
            d = 1;
        else if (s[0] == 'L')
            d = 2;
        else if (s[0] == 'R')
            d = 3;
        zombie[x][y][0] = true;
        for (int j = 1; j < k; ++j)
        {
            x += dx[d];
            y += dy[d];
            zombie[x][y][loop - j] = zombie[x][y][j % loop] = true;
        }
    }
    int ans = 0;
    queue<node> q;
    q.push(start);
    vis[start.x][start.y][start.t] = true;
    while (!q.empty())
    {
        node cur = q.front();
        q.pop();
        if (maze[cur.x][cur.y] == 'A')
        {
            ans = cur.t;
            break;
        }
        int ct = cur.t + 1;
        for (int i = 0; i < 4; ++i)
        {
            int cx = cur.x + dx[i];
            int cy = cur.y + dy[i];
            if (cx < 1 || cx > n || cy < 1 || cy > m)
                continue;
            if (maze[cx][cy] == '&')
                continue;
            if (zombie[cx][cy][ct % loop])
                continue;
            if (vis[cx][cy][ct % loop])
                continue;
            q.push(node(cx, cy, ct));
            vis[cx][cy][ct % loop] = true;
        }
    }

    if (ans == 0)
        printf("Oh no\n");
    else
        printf("%d\n", ans);
    return 0;
}