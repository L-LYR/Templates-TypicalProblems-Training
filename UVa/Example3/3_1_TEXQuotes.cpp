#include <stdio.h>
int main(void)
{
    // FILE *b = freopen("output.txt", "w", stdout);
    int q = 1;
    char c;
    while ((c = getchar()) != EOF)
    {
        if (c == '"')
        {
            printf("%s", q ? "``" : "''");
            q = !q;
        }
        else
            putchar(c);
    }
    // fclose(b);
    return 0;
}