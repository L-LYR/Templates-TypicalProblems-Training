// trie template
#include <iostream>
#include <cstring>
using namespace std;
struct trie
{
    const static int maxn = 400005;
    const static int maxalpha = 30;

    int t[maxn][maxalpha];
    int sum[maxn];
    int tot;
    void init()
    {
        memset(t, 0, sizeof(t));
        memset(sum, false, sizeof(sum));
        tot = 0;
    }

    void insert(const string &str)
    {
        int len = str.length();
        int p = 0;
        for (int i = 0; i < len; ++i)
        {
            int c = str[i] - 'a';
            if (t[p][c] == 0)
                t[p][c] = ++tot;
            p = t[p][c];
            sum[p]++;
        }
    }

    int find(const string &str)
    {
        int len = str.length();
        int p = 0;
        for (int i = 0; i < len; ++i)
        {
            int c = str[i] - 'a';
            if (t[p][c] == 0)
                return 0;
            p = t[p][c];
        }
        return sum[p];
    }
} t;

int main(void)
{
    t.init();
    string str;
    while (getline(cin, str) && str != "")
        t.insert(str);
    while (cin >> str)
        cout << t.find(str) << endl;
    return 0;
}