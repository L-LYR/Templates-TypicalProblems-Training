#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int len;
    scanf("%d", &len);
    getchar();
    int c, cnt1 = 0, cnt6 = 0;
    for (int i = 0; i < len; ++i)
    {
        c = getchar() - '0';
        if (c == 1)
            cnt1++;
        else if (c == 6)
            cnt6++;
    }
    int cnt = (cnt1 < cnt6) ? cnt1 : (cnt6 - 1);
    printf("%d\n", cnt);

    return 0;
}