#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 5;
int ans[maxn];
int cnt[20];
char str[maxn];
int main(void)
{
    ll pc = 1;
    scanf("%s", str);
    for (char *p = str; *p; ++p)
    {
        if (*p != '+')
            cnt[*p - '0']++;
        else
            pc++;
    }

    int d = 0, n = 0;
    for (int i = 9; i >= 1; --i)
    {
        while (cnt[i] > 0)
        {
            ans[d] += i;
            cnt[i]--;
            n = (n + 1) % pc;
            if (n == 0)
                ++d;
        }
    }

    for (int i = 0; i < maxn; ++i)
    {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }

    int i;
    for (i = maxn; i >= 0; --i)
        if (ans[i] != 0)
            break;
    while (i >= 0)
    {
        printf("%d", ans[i]);
        --i;
    }
    printf("\n");
    return 0;
}