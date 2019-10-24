#include <stdio.h>
int main(void)
{
    const char *str = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    int i;
    char c;
    while ((c = getchar()) != EOF)
    {
        i = 1;
        while (str[i] != '\0' && str[i] != c)
            ++i;
        if (str[i] == c)
            putchar(str[i - 1]);
        else
            putchar(c);
    }
    return 0;
}