#include <algorithm>
#include <iostream>
using namespace std;
long long read(char ch)
{
    long long x = 0, f = 1;
    char c = ch;
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9' || c == ',')
    {
        if (c == ',')
        {
            c = getchar();
            continue;
        }
        x = (x << 1) + (x << 3) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int main(void)
{
    long long A, B;
    char ch;
    while ((ch = getchar()) != EOF)
    {
        A = read(ch);
        ch = getchar();
        B = read(ch);
        printf("%lld\n", A + B);
    }
    return 0;
}