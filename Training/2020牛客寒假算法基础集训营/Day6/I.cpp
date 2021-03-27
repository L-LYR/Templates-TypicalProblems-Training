#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 10;

int n;
int p[maxn], rk[maxn];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (rk[x] < rk[y])
        p[x] = y;
    else
    {
        p[y] = x;
        if (rk[x] == rk[y])
            rk[x]++;
    }
}
int d[505][505];
vector<int> e;
int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d", &d[i][j]);
            if (d[i][j] == 0)
                merge(i, j);
        }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (d[i][j] != d[j][i])
            {
                printf("No\n");
                return 0;
            }
            if (p[i] != i || p[j] != j)
                continue;
            bool flag = true;
            for (int k = 1; k <= n; ++k)
            {
                if (d[i][k] == 0 || d[j][k] == 0)
                    continue;
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    printf("No\n");
                    return 0;
                }
                else if (d[i][j] == d[i][k] + d[k][j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                e.push_back(d[i][j]);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (p[i] != i)
            cnt++;
    int num = e.size();
    if (num + cnt != n - 1)
        printf("No\n");
    else
    {
        printf("Yes\n");
        sort(e.begin(), e.end());
        for (int i = 0; i < cnt; ++i)
            printf("0\n");
        for (int i : e)
            printf("%d\n", i);
    }

    return 0;
}