#include <cstdio>
#include <cmath>
using namespace std;
int main(void)
{
    int n, zero = 0, one = 0, i;
    scanf("%d", &n);
    char c = getchar();
    while (--n >= 0)
    {
        c = getchar();
        if (c == 'z')
            ++zero;
        else if (c == 'n')
            ++one;
    }
    if (one)
    {
        putchar('1');
        for (i = 1; i < one; ++i)
        {
            putchar(' ');
            putchar('1');
        }
        for (i = 0; i < zero; ++i)
        {
            putchar(' ');
            putchar('0');
        }
    }
    else
    {
        putchar('0');
        for (i = 1; i < zero; ++i)
        {
            putchar(' ');
            putchar('0');
        }
    }

    putchar('\n');
    return 0;
}