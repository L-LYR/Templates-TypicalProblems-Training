#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
char s1[10], s2[10];
int reverseHash(ll x)
{
    int i = 0;
    do
    {
        char c = x % 26 + 'a';
        s2[i] = c;
        x /= 26;
        ++i;
    } while (x > 0);
    while (i < 6)
    {
        s2[i] = 'a';
        ++i;
    }
    return i;
}
ll Hash(char *str)
{
    ll res = 0;
    for (int i = 0; i < 6; i++)
        res = (res * 26 + str[i] - 'a');
    return res;
}
int main(void)
{
    ll mod;
    while (scanf("%s %lld", s1, &mod) == 2)
    {
        ll cur = Hash(s1);
        cur += mod;
        if (cur <= 308915775)
        {
            memset(s2, 0, sizeof(s2));
            int i = reverseHash(cur);
            reverse(s2, s2 + i);
            printf("%s\n", s2);
        }
        else
            printf("-1\n");
    }
    return 0;
}