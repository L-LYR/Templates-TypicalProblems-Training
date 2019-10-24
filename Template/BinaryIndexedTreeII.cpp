#include <bits/stdc++.h>
using namespace std;
#define MAXN 500001
int darr[MAXN];
int tarr[MAXN];

inline int lowbit(int x)
{
    return x & -x;
}

inline int sum(int loc)
{
    int ret = 0;
    while (loc > 0)
    {
        ret += tarr[loc];
        loc -= lowbit(loc);
    }
    return ret;
}

inline void update(int loc, int n, int val)
{
    while (loc <= n)
    {
        tarr[loc] += val;
        loc += lowbit(loc);
    }
}

int main(void)
{
    int N, M, i, cur, last = 0;
    cin >> N >> M;
    for (i = 1; i <= N; ++i)
    {
        cin >> cur;
        darr[i] = cur - last;
        last = cur;
        update(i, N, darr[i]);
    }
    for (i = 1; i <= N; ++i)
        cout << darr[i] << " ";
    cout << endl;
    for (i = 1; i <= N; ++i)
        cout << tarr[i] << " ";
    cout << endl;
    int opt, x, y, k;
    for (i = 1; i <= M; ++i)
    {
        cin >> opt;
        switch (opt)
        {
        case 1:
            cin >> x >> y >> k;
            darr[x] += k;
            darr[y + 1] -= k;
            update(x, N, k);
            update(y + 1, N, -k);
            break;
        case 2:
            cin >> x;
            cout << sum(x) << endl;
            break;
        default:
            break;
        }
    }
    return 0;
}