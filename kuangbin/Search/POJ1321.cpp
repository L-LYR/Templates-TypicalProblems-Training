/*
 * 1. pay attention to the number of chesses which will
 *    be less or more than the number of chess board.
 * 2. search row by row while make a bool array col[maxn]
 *    for locating the previous chesses.
 */
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10;
char board[maxn][maxn];
bool col[maxn];
int n, k;

int dfs(int u, int d)
{
    if (d == 0)
        return 1;
    if (u > n)
        return 0;
    int res = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (col[i] == false && board[u][i] == '#')
        {
            col[i] = true;
            res += dfs(u + 1, d - 1);
            col[i] = false;
        }
    }
    return res + dfs(u + 1, d);
}

int main(void)
{
    while (scanf("%d%d", &n, &k) == 2 && n != -1)
    {
        for (int i = 1; i <= n; ++i)
            scanf("%s", board[i] + 1);
        printf("%d\n", dfs(1, k));
        memset(board, 0, sizeof(board));
    }
    return 0;
}