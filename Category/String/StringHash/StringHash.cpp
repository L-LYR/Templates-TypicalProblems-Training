// https://www.luogu.com.cn/problem/P3370
// string hash template
// luogu P3370

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10005;
unsigned long long dic[maxn];

unsigned long long SDBM_hash(char *str)
{
    unsigned long long hash = 0;
    while (*str)
    {
        // 65599 == 2^6 + 2^16 - 1
        // equivalent to
        // hash[i] = hash[i - 1] * 65599 + str[i];

        // let it overflow
        hash = (hash << 6) + (hash << 16) - hash + *str;
        str++;
    }
    return hash & 0x7fffffff;
}

unsigned long long BKDR_hash(char *str)
{
    unsigned long long seed = 131;
    unsigned long long hash = 0;
    while (*str)
    {
        // let it overflow
        hash = hash * seed + *str;
        str++;
    }
    return hash & 0x7fffffff;
}

int main(void)
{
    int n, ans = 0;
    scanf("%d", &n);
    char str[1505];
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", str);
        // dic[i] = SDBM_hash(str);
        dic[i] = BKDR_hash(str);
    }
    sort(dic, dic + maxn, greater<unsigned long long>());
    for (int i = 0; i < n; ++i)
    {
        if (!(dic[i] == dic[i + 1]))
            ++ans;
    }
    printf("%d\n", ans);
    return 0;
}