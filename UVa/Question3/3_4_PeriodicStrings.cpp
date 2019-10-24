#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int judge(char *begin, int forward, int period)
{
    while (begin[forward] != '\0')
    {
        if (begin[forward] != begin[forward % period])
            return 0;
        ++forward;
    }
    return 1;
}

int main(void)
{
    int n;
    char str[BUFFER_SIZE];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", str);
        int len = strlen(str);
        for (int j = 1; j <= len; ++j)
        {
            if (str[j] == str[0] && len % j == 0 && judge(str, j + 1, j))
            {
                printf("%d\n", j);
                break;
            }
            else if (j == len)
                printf("%d\n", j);
        }
        if (i != n - 1)
            printf("\n");
    }
    return 0;
}