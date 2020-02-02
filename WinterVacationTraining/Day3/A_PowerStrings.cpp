#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

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
            cout << 1 << endl;
        else
            cout << len / tLen << endl;

        memset(str, 0, sizeof(str));
    }
}