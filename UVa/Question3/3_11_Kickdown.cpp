#include <stdio.h>
#include <string.h>

#define MAX_SCALE 101

int match(char *move, char *still)
{
    char *p1 = move, *p2 = still;
    int len1 = strlen(move), len2 = strlen(still);
    int min = len1 + len2, i, flag, cur, surplus;
    while (*p2 != '\0')
    {
        flag = 1;
        for (i = 0; p2[i] != '\0' && p1[i] != '\0'; ++i)
            if (p2[i] + p1[i] - 96 > 3)
            {
                flag = 0;
                break;
            }
        if (flag == 1)
        {
            flag = 0;
            surplus = p2 - still;
            cur = surplus + ((len1 > (len2 - surplus)) ? len1 : (len2 - surplus));
            if (cur <= min)
                min = cur;
            else
                break;
        }
        ++p2;
    }
    return min;
}

int main(void)
{
    // FILE *b = freopen("output.txt", "w", stdout);
    char line1[MAX_SCALE], line2[MAX_SCALE];
    int min1, min2;

    while (scanf("%s\n%s", line1, line2) == 2)
    {
        min1 = match(line1, line2);
        min2 = match(line2, line1);
        printf("%d\n", (min2 > min1) ? min1 : min2);
    }
    // fclose(b);
    return 0;
}