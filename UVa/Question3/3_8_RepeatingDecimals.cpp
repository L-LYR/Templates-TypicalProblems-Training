#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIMIT 50

int Find(int *begin, int lim, int target)
{
    if (lim == 0)
        return -1;
    int i;
    for (i = 0; i < lim; ++i)
        if (target == begin[i])
            return i;
    return -1;
}

int main(void)
{
    // FILE *b = freopen("output.txt", "w", stdout);
    int x, y, period, z;
    int i, j, k, remainder[3050], quotient[3050], find, temp, stack[4];
    const char *conclusion = "number of digits in repeating cycle";
    char result[100], *p;
    while (scanf("%d %d", &x, &y) == 2)
    {
        i = period = -1;
        p = result;
        z = x;
        memset(remainder, 0, sizeof(remainder));
        memset(quotient, 0, sizeof(quotient));
        memset(result, 0, sizeof(result));

        do
        {
            ++i;
            remainder[i] = z % y;
            quotient[i] = z / y;
            z = remainder[i] * 10;
        } while ((find = Find(remainder, i, remainder[i])) == -1);
        period = i - find;

        if (quotient[0] != 0)
        {
            temp = quotient[0];
            k = 0;
            while (temp != 0)
            {
                stack[k++] = temp % 10;
                temp /= 10;
            }
            for (k = k - 1; k >= 0; --k)
                *p++ = stack[k] + '0';
        }
        else
            *p++ = '0';

        *p++ = '.';
        for (j = 1; j <= find; ++j)
            *p++ = quotient[j] + '0';
        *p++ = '(';
        for (j = find + 1; j <= LIMIT && j <= i; ++j)
            *p++ = quotient[j] + '0';
        if (j > LIMIT && i > LIMIT)
            strcat(result, "...)");
        else
            *p++ = ')';

        printf("%d/%d = %s\n", x, y, result);
        printf("   %d = %s\n\n", period, conclusion);
    }

    // fclose(b);
    return 0;
}