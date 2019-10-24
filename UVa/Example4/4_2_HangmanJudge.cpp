#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10000
#define ERROR_MAX_TIMES 6

const char *result[] = {"You win.", "You lose.", "You chickened out."};

int guess(char *ans, char *user, int *flag)
{
    *flag = 1;
    int mark[26], error = 0, bingo, len = strlen(ans);
    memset(mark, 0, sizeof(mark));
    char *up = user, *ap;
    while (*up != '\0')
    {
        if (mark[*up - 'a'] != 0)
        {
            ++up;
            ++error;
            continue;
        }
        ++mark[*up - 'a'];

        ap = ans;
        bingo = 0;
        while (*ap != '\0')
        {
            if (*ap == *up)
            {
                *ap = '0';
                bingo = 1;
                --len;
            }
            ++ap;
        }
        if (bingo == 0)
            ++error;
        if (len == 0)
            return error;
        ++up;
    }
    if (len > 0)
        *flag = 0;
    return error;
}

int main(void)
{
    // FILE *f = freopen("output.txt", "w", stdout);
    int num, flag, ret;
    char ans[BUFFER_SIZE], user[BUFFER_SIZE];
    while (scanf("%d", &num) == 1 && num != -1)
    {
        scanf("%s\n%s", ans, user);
        printf("Round %d\n", num);
        if ((ret = guess(ans, user, &flag)) > ERROR_MAX_TIMES)
            printf("%s\n", result[1]);
        else if (flag == 1)
            printf("%s\n", result[0]);
        else
            printf("%s\n", result[2]);
    }
    // fclose(f);
    return 0;
}