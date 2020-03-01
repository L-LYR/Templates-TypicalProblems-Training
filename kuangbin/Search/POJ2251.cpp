/* 
 * 1. had better to get input by getchar()
 * 2. pay attention to subscripts
 */
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 35;
char maze[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
struct node
{
    int x, y, z, t;
    node(int x_ = 0, int y_ = 0, int z_ = 0, int t_ = 0)
        : x(x_), y(y_), z(z_), t(t_) {}
} start;
int L, R, C;
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int main(void)
{
    while (scanf("%d%d%d", &L, &R, &C) == 3 && L != 0)
    {
        memset(vis, 0, sizeof(vis));
        memset(maze, 0, sizeof(maze));
        getchar();
        char temp;
        for (int k = 0; k < L; ++k)
        {
            for (int i = 0; i < R; ++i)
            {
                for (int j = 0; j < C; ++j)
                {
                    temp = getchar();
                    if (temp == 'S')
                        start = node(i, j, k, 0);
                    maze[k][i][j] = temp;
                }
                getchar();
            }
            getchar();
        }
        int ans = -1;
        queue<node> q;
        q.push(start);
        vis[start.z][start.x][start.y] = true;
        while (!q.empty())
        {
            node cur = q.front();
            q.pop();

            if (maze[cur.z][cur.x][cur.y] == 'E')
            {
                ans = cur.t;
                break;
            }

            for (int i = 0; i < 6; ++i)
            {
                int cx = cur.x + dx[i];
                int cy = cur.y + dy[i];
                int cz = cur.z + dz[i];
                if (cx < 0 || cx >= R || cy < 0 || cy >= C || cz < 0 || cz >= L)
                    continue;
                if (maze[cz][cx][cy] == '#')
                    continue;
                if (vis[cz][cx][cy])
                    continue;
                vis[cz][cx][cy] = true;
                q.push(node(cx, cy, cz, cur.t + 1));
            }
        }
        if (ans == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", ans);
    }
    return 0;
}