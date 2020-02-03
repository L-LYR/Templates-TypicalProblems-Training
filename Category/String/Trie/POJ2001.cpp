#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
// #define DEBUG

const int maxn = 1010;
const int maxlen = 25;
char str[maxn][maxlen];

struct trie
{
    const static int maxn = 200005;
    const static int maxalpha = 30;

    int t[maxn][maxalpha];
    int s[maxn];
    int tot;

    void init()
    {
        memset(t, 0, sizeof(t));
        memset(s, 0, sizeof(s));
        tot = 0;
    }

    void insert(char *str)
    {
        for (int p = 0; *str; str++)
        {
            int c = *str - 'a';
            if (t[p][c] == 0)
                t[p][c] = ++tot;
            p = t[p][c];
            s[p]++;
        }
    }

    char *getAbbr(char *str, char *abbr)
    {
        char *h = abbr;
        for (int p = 0; *str; str++)
        {
            int c = *str - 'a';
            // if (t[p][c] == 0) // impossible in this question
            //     return NULL;
            p = t[p][c];

            *abbr++ = *str;

            if (s[p] == 1) // find the unique prefix of the current word
                break;
        }
        *abbr = '\0';
        return h;
    }

} t;

int main(void)
{
    t.init();
    int n = 0;
#ifdef DEBUG
    freopen("./input", "r", stdin);
#endif
    while (scanf("%s", str[n]) != EOF)
    {
        t.insert(str[n]);
        n++;
    }
    char abbr[maxlen];
    for (int i = 0; i < n; ++i)
        printf("%s %s\n", str[i], t.getAbbr(str[i], abbr));
    return 0;
}