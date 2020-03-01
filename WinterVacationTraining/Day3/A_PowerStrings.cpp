#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

/*
    Supposing that the length of string s is l, there exists a 
    sub-string s' which is the repeating period of s if and only if
                    l % (l - kmpNext[l]) == 0
proof:
    Supposing that s = c_1c_2c_3...c_l, kmpNext[l] = k, we have 
            s' = s[1...(l - k)] = c_1c_2...c_(l - k)
    Considering the definition of kmpNext-array, we know
                s[1...k] == s[(l - k + 1)...l]
    So if l % (l - k) == 0, we get l = m(l - k)
        s[1...(l - k)] == s[(l - k + 1)...2(l - k)]
                       == s[(2(l - k) + 1)...3(l - k)]
                       == ...
                       == s[((m - 1)(l - k) + 1)...m(l - k)]
                       == s[((m - 1)(l - k) + 1)... l]
*/

const int maxn = 1000005;
char str[maxn];
int kmpNext[maxn];
int len;

void getNext(void)
{
    memset(kmpNext, 0, sizeof(kmpNext));
    int i = 0, j = -1;
    kmpNext[0] = -1;
    while (i < len)
    {
        if (j == -1 || str[i] == str[j])
            kmpNext[++i] = ++j;
        else
            j = kmpNext[j];
    }
}

int main(void)
{
    while ((scanf("%s", str) == 1) && str[0] != '.')
    {
        len = strlen(str);
        getNext();
        int tLen = len - kmpNext[len];
        if (kmpNext[len] == 0 || len % tLen != 0)
            printf("1\n");
        else
            printf("%d\n", len / tLen);

        memset(str, 0, sizeof(str));
    }
}