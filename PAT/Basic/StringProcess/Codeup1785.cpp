#include <iostream>
using namespace std;
int main(void)
{
    char a[105], b[105], ans[210];
    while (scanf("%s %s", &a, &b) != EOF)
    {
        char *p = a, *s = ans;
        while (*p)
            *s++ = *p++;
        p = b;
        while (*p)
            *s++ = *p++;
        *s = '\0';
        printf("%s\n", ans);
    }
    return 0;
}