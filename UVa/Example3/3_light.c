#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    int m, n, k, i;
    while (scanf("%d%d", &n, &m) && n != 0 && m != 0)
    {
        int *a = (int *)malloc(sizeof(int) * (n + 1));
        memset(a, 0, sizeof(int) * (n + 1));
        for (i = 1; i <= m; i++)
            for (k = 1; k * i <= n; k++)
                a[k * i] = !a[k * i];
        for (k = 1; k <= n; k++)
            if (a[k])
                printf("%d ", k);
        printf("\n");
        free(a);
    }
    system("pause");
    return 0;
}