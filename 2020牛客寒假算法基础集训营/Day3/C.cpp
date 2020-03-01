#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1005;
int a[maxn * maxn];
int main(void)
{
    int T;
    scanf("%d", &T);
    while (T-- > 0)
    {
        int n, m, p;
        scanf("%d%d%d", &n, &m, &p);
        memset(a, 0, sizeof(a));
        bool error = false, flag = false;
        for (int i = 0; i < p; ++i)
        {
            int x, y, val;
            scanf("%d%d%d", &x, &y, &val);
            if (x < 0 || x >= n || y < 0 || y >= m)
                flag = true;
            int l = x * m + y;
            if (l < 0 || l >= m * n)
            {
                error = true;
                continue;
            }
            else
                a[l] = val;
        }
        if (error)
            printf("Runtime error\n");
        else
        {
            for (int i = 0; i < n; ++i)
            {
                printf("%d", a[i * m + 0]);
                for (int j = 1; j < m; ++j)
                    printf(" %d", a[i * m + j]);
                printf("\n");
            }
            if (flag)
                printf("Undefined Behaviour\n");
            else
                printf("Accepted\n");
        }
    }

    return 0;
}