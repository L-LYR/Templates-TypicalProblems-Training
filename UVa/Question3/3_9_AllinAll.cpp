#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100000

int main(void)
{
    // FILE *b = freopen("output.txt", "w", stdout);
    char s[BUFFER_SIZE], t[BUFFER_SIZE];
    // char *sp, *tp, *last;
    // int flag;
    while (scanf("%[^ ]%*c%s%*c", s, t) == 2)
    {
        // sp = s;
        // last = t;
        // flag = 1;
        // while (*sp != '\0')
        // {
        //     tp = strchr(last, *sp);
        //     if (tp == NULL)
        //     {
        //         printf("No\n");
        //         flag = 0;
        //         break;
        //     }
        //     ++sp;
        //     if (*tp == '\0' && *sp != '\0')
        //     {
        //         printf("No\n");
        //         flag = 0;
        //         break;
        //     }
        //     last = tp + 1;
        // }
        // if (flag == 1)
        //     printf("Yes\n");
        //the most easy way
        int j = 0;
        for (int i = 0; i < strlen(t); ++i)
            if (t[i] == s[j])
                ++j;
        if (j == strlen(s))
            printf("Yes\n");
        else
            printf("No\n");
    }
    // fclose(b);
    return 0;
}