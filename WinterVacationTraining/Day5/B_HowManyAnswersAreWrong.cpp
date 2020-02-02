#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 200005;
const int maxm = 40005;

int parent[maxn];
int len[maxn];

int find(int son)
{
    if (parent[son] == son)
        return son;
    int p = parent[son];
    parent[son] = find(p);
    len[son] += len[p];
    return parent[son];
}

int main(void)
{
    int n, m;
    while (scanf("%d %d", &n, &m) == 2)
    {
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
        memset(len, 0, sizeof(len));
        int a, b, s, ans = 0;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &s);
            --a;
            // make the smaller one the new parent
            // ap < bp
            // [a,b] = [ap,b] - [ap,a] = [ap,bp] + [bp,b] - [ap,a]
            // ap > bp
            // [a,b] = [bp,b] - [bp,a] = [bp,b] - [bp,ap] - [ap,a]
            int ap = find(a);
            int bp = find(b);
            if (ap < bp)
            {
                parent[bp] = ap;
                len[bp] = len[a] + s - len[b];
            }
            else if (bp < ap)
            {
                parent[ap] = bp;
                len[ap] = len[b] - s - len[a];
            }
            else
            {
                if (len[b] - len[a] != s)
                    ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}