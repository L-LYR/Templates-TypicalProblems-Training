#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
// #define DEBUG
struct Trie
{
    const static int maxn = 200005;
    const static int maxalpha = 12;

    int t[maxn][maxalpha];
    int tot;
    bool isNum[maxn];

    void init()
    {
        memset(t, 0, sizeof(t));
        memset(isNum, false, sizeof(isNum));
        tot = 0;
    }

    void insert(char *str)
    {
        int p;
        for (p = 0; *str; ++str)
        {
            int c = *str - '0';
            if (t[p][c] == 0)
                t[p][c] = ++tot;
            p = t[p][c];
        }
        isNum[p] = true; // the phone number end
    }
    bool find(char *str)
    {
        int p;
        for (p = 0; *(str + 1); ++str) // *(str+1) important!
        {
            int c = *str - '0';
            p = t[p][c];
            if (isNum[p]) // There exit other phone numbers.
                return true;
        }
        return false;
    }
} trie;
const int maxn = 10005;
const int maxlen = 45;
char str[maxn][maxlen];
int main(void)
{

#ifdef DEBUG
    freopen("./input", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        trie.init();
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; ++j)
        {
            scanf("%s", str[j]);
            trie.insert(str[j]);
        }
        bool flag = false;
        for (int j = 0; j < n; ++j)
        {
            if (trie.find(str[j]))
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}