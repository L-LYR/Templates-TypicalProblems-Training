#include <bits/stdc++.h>
using namespace std;
#define MAXN 500001
int arr[MAXN];
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
    int M, N, i;
    cin >> N >> M;
    for (i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        update(i, N, arr[i]);
    }

    int opt, x, y;
    for (i = 1; i <= M; ++i)
    {
        cin >> opt >> x >> y;
        switch (opt)
        {
        case 1:
            arr[x] += y;
            update(x, N, y);
            break;
        case 2:
            cout << sum(y) - sum(x - 1) << endl;
            break;
        default:
            break;
        }
    }

    return 0;
}