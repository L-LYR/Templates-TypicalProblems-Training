#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count(int *arr, char *str)
{
    while (*str != '\0')
        ++arr[*(str++) - 'A'];
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int ChCount1[26], ChCount2[26];
    char buffer[100];
    int flag;
    while (scanf("%s", buffer) == 1)
    {
        flag = 1;

        memset(ChCount1, 0, sizeof(ChCount1));
        memset(ChCount2, 0, sizeof(ChCount2));

        count(ChCount1, buffer);
        scanf("%s", buffer);
        count(ChCount2, buffer);

        qsort(ChCount1, 26, sizeof(int), cmp);
        qsort(ChCount2, 26, sizeof(int), cmp);

        for (int i = 0; i < 26; ++i)
            if (ChCount1[i] != ChCount2[i])
            {
                flag = 0;
                break;
            }

        if (flag == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}