#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    while (scanf("%d", &n) && n > 0)
    {
        int i=0, row, col, d = 0;
        int *a = (int *)malloc(sizeof(int) * n * n);
        while (d <= n / 2)
        {
            for (row = d, col = n - 1 - d; row <= n - 1 - d; row++)
                *(a + col + row * n) = i++;
            for (row--, col--; col >= d; col--)
                *(a + col + row * n) = i++;
            for (col++, row--; row >= d; row--)
                *(a + col + row * n) = i++;
            for (row++, col++; col <= n - 2 - d; col++)
                *(a + col + row * n) = i++;
            d++;
        }
        for (i = 0; i < n * n; i++)
        {
            printf("%5d", *(a + i));
            if ((i + 1) % n == 0)
                printf("\n");
        }
        free(a);
    }
    system("pause");
    return 0;
}