#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

int compare(char *str, int pc1, int pc2, int length)
{
    char *p, *q;
    for (int i = 0; i < length; ++i)
    {
        p = str + (pc1 + i) % length;
        q = str + (pc2 + i) % length;
        if (*p != *q)
            return *p - *q;
    }
    return 0;
}

int main(void)
{
    // FILE *f = freopen("output.txt", "w", stdout);
    char str[100];
    int loc, T, length;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        loc = 0;
        scanf("%s", str);
        length = strlen(str);
        for (int temp = 1; temp < length; ++temp)
            if (compare(str, loc, temp, length) > 0)
                loc = temp;
        printf("%s", str + loc);
        str[loc] = '\0';
        printf("%s\n", str);
    }
    // fclose(f);
    return 0;
}