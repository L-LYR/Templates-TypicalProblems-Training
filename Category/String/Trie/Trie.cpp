#include <iostream>
#include <cstring>
using namespace std;
struct normalTrie
{
    const static int maxn = 2000005;
    const static int maxalpha = 30; // max-number of sons

    int t[maxn][maxalpha]; // nodes, s[i][j] means node i-th's j-th son
    int sum[maxn];         // the number of words beginning with "xxx"
    bool isWord[maxn];
    int tot;

    void init()
    {
        memset(t, 0, sizeof(t));
        memset(sum, 0, sizeof(sum));
        memset(isWord, false, sizeof(isWord));
        tot = 0;
    }

    void insert(char *str)
    {
        int len = strlen(str);
        int p = 0;
        for (int i = 0; i < len; i++)
        {
            int c = str[i] - '0';
            if (t[p][c] == 0)
                t[p][c] = ++tot;
            p = t[p][c];
            sum[p]++;
        }
        isWord[p] = true;
    }

    int find(char *str)
    {
        int len = strlen(str);
        int p = 0;
        for (int i = 0; i < len; i++)
        {
            int c = str[i] - '0';
            if (t[p][c] == 0)
                return 0;
            p = t[p][c];
        }
        return sum[p];
    }

    void insert(string str) { this->find(str.c_str()); }
    int find(string str) { return this->find(str.c_str()); }

} trie;
