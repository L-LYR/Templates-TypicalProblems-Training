#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    int cnt[105], s;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &s);
        cnt[s]++;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &s);
        if (i > 0)
            putchar(' ');
        printf("%d", cnt[s]);
    }
    putchar('\n');
    return 0;
}