#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
// #define DEBUG
using namespace std;
map<char, int> m;
map<int, char> rm;
const string gene = "AGCT";
struct Trie
{
    const static int maxn = 1000005;
    const static int maxalpha = 4;

    int t[maxn][maxalpha];
    int s[maxn];
    int tot, ans;
    void init()
    {
        memset(t, 0, sizeof(t));
        memset(s, 0, sizeof(s));
        ans = tot = 0;
    }

    void insert(char *str)
    {
        int len = strlen(str);
        for (int p = 0, i = 0; i < len; ++i)
        {
            int c = m[str[i]];
            if (t[p][c] == 0)
                t[p][c] = ++tot;
            p = t[p][c];
            s[p]++;
            ans = max(ans, s[p] * (i + 1)); // calculate the answer while inserting
        }
    }
} trie;

const int maxlen = 55;
int main(void)
{
#ifdef DEBUG
    freopen("./input", "r", stdin);
    freopen("./output", "w", stdout);
#endif
    for (int i = 0; i < gene.length(); ++i)
    {
        m[gene[i]] = i;
        rm[i] = gene[i];
    }
    int T;
    scanf("%d", &T);
    for (int c = 1; c <= T; ++c)
    {
        trie.init();

        int n;
        scanf("%d", &n);
        char str[maxlen];
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", str);
            trie.insert(str);
        }
        printf("Case %d: %d\n", c, trie.ans);
    }
    return 0;
}